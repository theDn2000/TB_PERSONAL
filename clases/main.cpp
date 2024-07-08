#include <iostream>
#include <vector>

using namespace std;

class Complejo
{
    friend: Complejo operator+(Complejo const &a, Complejo const &b);
    private:
        float real;
        float imaginary;
    public:
    Complejo(float real, float imaginary) : real{real}, imaginary{imaginary} {}

    float getModule() const
    {
        return sqrt(real * real + imaginary * imaginary);
    }
}

Complejo suma(Complejo const &a, Complejo const &b)
{
    return Complejo(a.real + b.real, a.imaginary + b.imaginary);
}

Complejo operator+(Complejo const &a, Complejo const &b)
{
    return Complejo(a.real + b.real, a.imaginary + b.imaginary);
}

class Person
{
    private:
        string name;
        int age;
        vector<string> asignaturas;
    public:
        Person(string name, int age, vector<string> asignaturas)
        {
            this->name = name;
            this->age = age;
            this->asignaturas = asignaturas;
        }
        string getPerson()
        {
            cout << "Nombre: " << name << " Edad: " << age << " Asignaturas: ";
            for (auto asignatura : asignaturas)
            {
                cout << asignatura << " ";
            }
            cout << endl;
        }
};

// Herencia
class Profesor : public Person
{
    private:
        string professor_id;
    public:
        //Constructor
        Profesor(string name, int age, vector<string> asignaturas, string professor_id) : Person(name, age, asignaturas) {
            this->professor_id = professor_id;
        }
        // Metodos
        string get_id()
        {
            cout << "ID: " << professor_id << endl;
            return professor_id;
        }
};

class Alumno : public Person
{
    public:
        //Constructor
        Alumno(string name, int age, vector<string> asignaturas) : Person(name, age, asignaturas) {}    
};

int main()
{
    vector<string> asignaturas = {"Matematicas", "Fisica", "Quimica"};
    vector<string> asignaturas2 = {"Historia"};

    Profesor juan = Profesor("Juan", 45, asignaturas2, "1234");
    Alumno pedro = Alumno("Pedro", 20, asignaturas);

    juan.getPerson();
    juan.get_id();

    pedro.getPerson();

    return 0;
}

/*
class RegularPolygon
{
    protected:
        int side;
        int sidenumber;
}

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
                // throw exception
                throw "El radio no puede ser negativo";
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
            return side*sqrt(3)/2;
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

class Pentagon : public RegularPolygon
{
    public:
        Pentagon (int side) : RegularPolygon(side) {}
}
{
    private:
        int side;
    public:
        Pentagon(int side)
        {
            this->side = side;
        }
        float getArea()
        {
            return (side * side) / 2;
        }
        float getPerimeter()
        {
            return 5 * side;
        }
        float print()
        {
            cout << "Soy un pentagono de lado " << side << endl;
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
*/