#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <algorithm>

struct Point2D {
    double x;
    double y;
};

struct Particle {
    Point2D position;
    double weight;
};

class MonteCarloLocalization {
public:
    MonteCarloLocalization(int num_particles, const std::vector<Point2D>& flags, double sensor_noise)
        : num_particles(num_particles), flags(flags), sensor_noise(sensor_noise) {
        // Initialize particles randomly in the field
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis_x(0.0, 105.0); // Width of the soccer field
        std::uniform_real_distribution<> dis_y(0.0, 68.0); // Height of the soccer field

        for (int i = 0; i < num_particles; ++i) {
            particles.push_back({{dis_x(gen), dis_y(gen)}, 1.0 / num_particles});
        }
    }

    void update_with_motion(double dx, double dy) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> motion_noise_x(0.0, 1.0); // Motion noise
        std::normal_distribution<> motion_noise_y(0.0, 1.0);

        for (auto& particle : particles) {
            particle.position.x += dx + motion_noise_x(gen);
            particle.position.y += dy + motion_noise_y(gen);
        }
    }

    void update_with_measurement(const std::vector<std::pair<Point2D, double>>& observations) {
        for (auto& particle : particles) {
            particle.weight = 1.0;
            for (const auto& obs : observations) {
                const auto& landmark = obs.first;
                double measured_dist = obs.second;
                double predicted_dist = distance(particle.position, landmark);
                double weight = gaussian(measured_dist, sensor_noise, predicted_dist);
                particle.weight *= weight;
            }
        }
        normalize_weights();
    }

    void resample_particles() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::vector<Particle> new_particles;
        std::uniform_real_distribution<> dis(0.0, 1.0);

        std::vector<double> cumulative_sum;
        double sum = 0.0;
        for (const auto& particle : particles) {
            sum += particle.weight;
            cumulative_sum.push_back(sum);
        }

        for (int i = 0; i < num_particles; ++i) {
            double sample = dis(gen) * sum;
            auto it = std::lower_bound(cumulative_sum.begin(), cumulative_sum.end(), sample);
            int index = it - cumulative_sum.begin();
            new_particles.push_back(particles[index]);
        }
        particles = new_particles;
    }

    Point2D estimate_position() const {
        double x_sum = 0.0, y_sum = 0.0, weight_sum = 0.0;
        for (const auto& particle : particles) {
            x_sum += particle.position.x * particle.weight;
            y_sum += particle.position.y * particle.weight;
            weight_sum += particle.weight;
        }
        return {x_sum / weight_sum, y_sum / weight_sum};
    }

private:
    int num_particles;
    double sensor_noise;
    std::vector<Point2D> flags;
    std::vector<Particle> particles;

    double distance(const Point2D& a, const Point2D& b) const {
        return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }

    double gaussian(double mu, double sigma, double x) const {
        return std::exp(-0.5 * std::pow((x - mu) / sigma, 2.0)) / (sigma * std::sqrt(2.0 * M_PI));
    }

    void normalize_weights() {
        double sum = 0.0;
        for (const auto& particle : particles) {
            sum += particle.weight;
        }
        for (auto& particle : particles) {
            particle.weight /= sum;
        }
    }
};


const std::vector<Point2D> flags = {
    {0.0, 0.0},        // Corner top-left
    {105.0, 0.0},      // Corner top-right
    {0.0, 68.0},       // Corner bottom-left
    {105.0, 68.0},     // Corner bottom-right
    {52.5, 0.0},       // Goal top-center
    {52.5, 68.0},      // Goal bottom-center
    {52.5, 34.0},      // Center of the field
    {0.0, 34.0},       // Left side-center
    {105.0, 34.0}      // Right side-center
};


int main() {
    // Inicialización del sistema MCL
    double sensor_noise = 5.0;
    MonteCarloLocalization mcl(1000, flags, sensor_noise);

    // Simulated measurements (landmark observed, distance measured)
    std::vector<std::pair<Point2D, double>> observations = {
        {{0.0, 0.0}, 50.0},
        {{105.0, 0.0}, 60.0},
        {{52.5, 34.0}, 30.0}
    };

    // Simulate robot motion and measurements
    for (int i = 0; i < 100; ++i) {
        // Simulate robot movement
        mcl.update_with_motion(5.0, 5.0);

        // Update based on measurement
        mcl.update_with_measurement(observations);

        // Resample particles
        mcl.resample_particles();

        // Estimate position
        Point2D estimated_pos = mcl.estimate_position();
        std::cout << "Estimated position: (" << estimated_pos.x << ", " << estimated_pos.y << ")\n";
    }

    return 0;
}
