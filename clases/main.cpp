#include <iostream>

using namespace std;

class Square
{
    private:
        int side;
    public:
        Square(int side)
        {
            this->side = side;
        }
        float getArea()
        {
            return side * side;
        }
        float getPerimeter()
        {
            return 4 * side;
        }
        float print()
        {
            cout << "Soy un cuadrado de lado " << side << endl;
        }
};

class Circle
{
    private:
        int radius;
        float area;
        float perimeter;
    public:
        Circle(int radius)
        {
            if (radius < 0)
            {
                cout << "El radio no puede ser negativo" << endl;
                return;
            }
            else
            {
                this->radius = radius;
            }
            
        }
        float getArea()
        {
            this->area = 3.1416 * radius * radius;
            return this->area;
        }
        float getPerimeter()
        {
            this->perimeter = 2 * 3.1416 * radius;
            return 2 * 3.1416 * radius;
        }
        float print()
        {
            cout << "Soy un circulo de radio " << radius << endl;
        }
};

class Triangle // Equilatero
{
    private:
        int side;
    public:
        Triangle(int side)
        {
            this->side = side;
        }
        float getArea()
        {
            return (side * side) / 2;
        }
        float getPerimeter()
        {
            return 3 * side;
        }
        float print()
        {
            cout << "Soy un triangulo de lado " << side << endl;
        }
};

int main()
{
    Square square = Square(5);
    Circle circle = Circle(-5);
    Triangle triangle = Triangle(5);

    square.print();
    cout << "Area: " << square.getArea() << endl;
    cout << "Perimetro: " << square.getPerimeter() << endl;

    circle.print();
    cout << "Area: " << circle.getArea() << endl;
    cout << "Perimetro: " << circle.getPerimeter() << endl;

    triangle.print();
    cout << "Area: " << triangle.getArea() << endl;
    cout << "Perimetro: " << triangle.getPerimeter() << endl;

    return 0;
}