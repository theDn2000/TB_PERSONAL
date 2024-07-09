#include "figuras.h"
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

int main(){

    cout << "Cuantas figuras quieres crear?" << endl;
    int n;
    cin >> n;

    vector<shared_ptr<FiguraGeometricaRegular>> figuras;

    while (n > 0)
    {
        cout << "Que figura quieres crear?" << endl;
        cout << "1. Cuadrado" << endl;
        cout << "2. Triangulo" << endl;
        cout << "3. Pentagono" << endl;
        int opcion;
        cin >> opcion;

        cout << "Cuanto mide el lado?" << endl;
        float lado;
        cin >> lado;

        switch (opcion)
        {
        case 1:
            figuras.push_back(dynamic_cast<shared_ptr<Cuadrado>>(new Cuadrado{lado}));
            n--;
            break;
        case 2:
            figuras.push_back(dynamic_cast<shared_ptr<TrianguloEq>>(new TrianguloEq{lado}));
            n--;
            break;
        case 3:
            figuras.push_back(dynamic_cast<shared_ptr<Pentagono>>(new Pentagono{lado}));
            n--;
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    }

    for (auto figura : figuras)
    {
        cout << "Area: " << figura->getArea() << endl;
        cout << "Perimetro: " << figura->getPerimetro() << endl;
        figura->queSoy();
        if (dynamic_cast<Cuadrado*>(figura.get()))
        {
            cout << "Diagonal: " << dynamic_cast<Cuadrado*>(figura.get())->getDiagonal() << endl;
        }
        else if (dynamic_cast<TrianguloEq*>(figura.get()))
        {
            cout << "Altura: " << dynamic_cast<TrianguloEq*>(figura.get())->getAltura() << endl;
        }
        else if (dynamic_cast<Pentagono*>(figura.get()))
        {
            cout << "Apotema: " << dynamic_cast<Pentagono*>(figura.get())->getApotema() << endl;
        }
    }

    /*
    Cuadrado c{5}; // Create an instance of the concrete class
    TrianguloEq t{5};
    Pentagono p{5};

    cout << "Cuadrado" << endl;
    cout << "Area: " << c.getArea() << endl;
    cout << "Perimetro: " << c.getPerimetro() << endl;
    cout << "Diagonal: " << c.getDiagonal() << endl;
    c.queSoy();

    cout << "Triangulo" << endl;
    cout << "Area: " << t.getArea() << endl;
    cout << "Perimetro: " << t.getPerimetro() << endl;
    cout << "Altura: " << t.getAltura() << endl;
    t.queSoy();

    cout << "Pentagono" << endl;
    cout << "Area: " << p.getArea() << endl;
    cout << "Perimetro: " << p.getPerimetro() << endl;
    cout << "Apotema: " << p.getApotema() << endl;
    p.queSoy();
    */

    
    return 0;
}































/*
#include <iostream>
#include <cmath>

using namespace std;

class Complejo
{
  friend Complejo operator+(Complejo const &c1, Complejo const &c2);
  friend ostream &operator<<(ostream &os, Complejo const &c);
  friend istream &operator>>(istream &is, Complejo &c);

public:
  Complejo(float real, float im) : real{real}, im{im}
  {
  }

  float getImaginario() const
  {
    return im;
  }

  float getReal() const
  {
    return real;
  }

  void setImaginario(float imaginario)
  {
    im = imaginario;
  }

  void setReal(float r)
  {
    real = r;
  }

  float getModule() const
  {
    return sqrt(real * real + im * im);
  }

private:
  float real;
  float im;
};

Complejo suma(Complejo const &c1, Complejo const &c2)
{
  return Complejo{c1.getReal() + c2.getReal(), c1.getImaginario() + c2.getImaginario()};
}

Complejo operator+(Complejo const &c1, Complejo const &c2)
{
  return Complejo{c1.real + c2.real, c1.im + c2.im};
}

ostream &operator<<(ostream &os, Complejo const &c)
{
  os << c.real << " + " << c.im << "i";
  return os;
}

istream &operator>>(istream &is, Complejo &c)
{
  is >> c.real >> c.im;
  return is;
}

int main()
{
  Complejo c1{1, 1};
  Complejo c2{3, 2};

  auto c3 = c1 + c2;

  cout << "Introduce un número complejo, separados por un espacio -> [real] [imaginario]: ";
    Complejo c4{0, 0};
    cin >> c4;
    cout << "El número complejo introducido es: " << c4 << endl;
    cout << "El módulo del número complejo introducido es: " << c4.getModule() << endl;

    cout << "Introduce otro número complejo, separados por un espacio -> [real] [imaginario]: ";
    Complejo c5{0, 0};
    cin >> c5;
    cout << "El número complejo introducido es: " << c5 << endl;
    cout << "El módulo del número complejo introducido es: " << c5.getModule() << endl;

    cout << "La suma de los números complejos es: " << c4 + c5 << endl;
}
*/
/*
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Complejo
{
    friend Complejo operator+(Complejo const &a, Complejo const &b);
    //friend...

    private:
        float real;
        float imaginary;
    public:
    Complejo(float real, float imaginary) : real{real}, imaginary{imaginary} {}

    float getModule() const
    {
        return sqrt(real * real + imaginary * imaginary);
    }
};

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
*/
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