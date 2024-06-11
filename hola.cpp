#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Car {
    string brand;
    string plate;
};

struct Person {
    string name;
    int age;
    string dni;
    string mail;
    Car car;
};

void printPerson(Person p) 
{
    p.name = "Pepe";
    cout << "Age: " << p.age << endl;
    cout << "DNI: " << p.dni << endl;
    cout << "Mail: " << p.mail << endl;
    cout << "Car brand: " << p.car.brand << endl;
}

void PrintPerson_optimus(Person &p) 
{
    p.name = "Pepe"; // EFECTO COLATERAL, se modifica el valor original NO SE DEBE HACER NUNCA!!!
    cout << "Age: " << p.age << endl;
    cout << "DNI: " << p.dni << endl;
    cout << "Mail: " << p.mail << endl;
    cout << "Car brand: " << p.car.brand << endl;
}

void PrintPerson_optimus_solved(Person const &p) 
{
    //p.name = "Pepe"; // EFECTO COLATERAL SOLUCIONADO, no se puede modificar el valor original
    cout << "Age: " << p.age << endl;
    cout << "DNI: " << p.dni << endl;
    cout << "Mail: " << p.mail << endl;
    cout << "Car brand: " << p.car.brand << endl;
}

// Print the name of the persons that are not minors
void print_adults(vector<Person> const &personas)
    {
        for (Person p : personas) 
        {
            if (p.age >= 18) {
                cout << p.name << endl;
            }
        }
    }

int main() {

    int myNumber{3};
    int myOtherNumber = 3;
    long myLongNumber{3};
    long long myLongLongNumber{3};
    unsigned int myUnsignedNumber{3};
    unsigned long myUnsignedLongNumber{3};
    unsigned long long myUnsignedLongLongNumber{3}; // Enteros largos sin signo

    float myFloatNumber{3.0}; // Decimales
    double myDoubleNumber{3.0}; // Decimales

    // habitualmente int, float

    // Text
    char myChar{'a'}; // Caracteres 
    //std::string myString{"Hola mundo"}; // Cadenas de texto
    string myString{"Hola mundo"}; // Cadenas de texto

    // Boolean
    bool myBoolean{true}; // Verdadero o falso

    // Structs
    Person alberto{"Alberto", 30, "12345678A", "alberto@mail.com", Car{"Seat", "1234ABC"}}; // Estructuras
    Person juan = {"Juan", 15, "12345678A", "juan@mail.com", Car{"Mini", "5678DEF"}};
    Person jose = {"Jose", 74, "12345678A", "jose@mail.com", Car{"Renault", "5678DEF"}};
    Person marta = {"Marta", 51, "12345678A", "marta@mail.com", Car{"Citroen", "5678DEF"}};
    Person claudia = {"Claudia", 8, "12345678A", "claudia@mail.com", Car{"Ferrari", "5678DEF"}};

    vector<Person> personas{alberto, juan};
    personas.push_back(jose);
    personas.push_back(marta);
    personas.push_back(claudia);



    print_adults(personas);


    //PrintPerson_optimus_solved(alberto);
    //std::cout << "Hola mundo, esto es una prueba secundaria" << std::endl;
    return 0;
}


