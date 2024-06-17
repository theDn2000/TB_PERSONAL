#include <memory>
#include <iostream>

#include "functions.h"

using namespace std;

void modifica(int x)
{
    x = 11;
}
void modificaP(shared_ptr<int> pX)
{
    *pX = 11;
}

// Clase persona
struct Person
{
    string name;
    int age;
    string dni;
    string mail;
    bool esAdulto;
};

// Personas adultas: con punteros
vector<shared_ptr<Person>> personas_adultas(vector<shared_ptr<Person>> &personas)
{
    vector<shared_ptr<Person>> personas_adultas;
    for (auto const &p : personas)
    {
        if (p->age >= 18)
        {
            personas_adultas.push_back(p);
        }
    }
    // Muestra en pantalla las personas adultas
    for (auto const &p : personas_adultas)
    {
        cout << "Nombre: " << (*p).name << endl;
    }
    // Modifica el valor esAdulto de las personas adultas
    for (auto const &p : personas_adultas)
    {
        p->esAdulto = true;
    }
    return personas_adultas;
}

// Personas adultas: con referencias
vector<Person> personas_adultas(vector<Person> &personas)
{
    vector<Person> personas_adultas;
    for (auto p : personas)
    {
        if (p.age >= 18)
        {
            personas_adultas.push_back(p);
        }
    }
    // Muestra en pantalla las personas adultas
    for (auto p : personas_adultas)
    {
        cout << "Nombre: " << p.name << endl;
    }
    // Modifica el valor esAdulto de las personas adultas
    for (auto &p : personas_adultas)
    {
        p.esAdulto = true;
    }
    return personas_adultas;
}



int main()
{
    int a = 5;
    shared_ptr<int> pA = make_shared<int>(5);
    shared_ptr<int> pB = pA;
    int b = a;

    *pB = 7;
    b = 7;

    cout << "a: " << a << endl;
    cout << "pA: " << *pA << endl;

    modifica(a);
    modificaP(pA);

    cout << "a modificado: " << a << endl;
    cout << "b: " << b << endl; // b no se modifica porque es una copia de a
    cout << "pA modificado: " << *pA << endl;
    cout << "pB: " << *pB << endl;

    //int ab = sumaa(a, b);
    //int pApB = sumaaP(pA, pB);

    //cout << "a + b: " << ab << endl;
    //cout << "pA + pB: " << pApB << endl;

    // Personas
    // Creamos personas
    Person alberto{"Alberto", 30, "12345678A", "alberto@mail.com", false}; // Estructuras
    Person juan = {"Juan", 15, "12345678A", "juan@mail.com", false};
    Person jose = {"Jose", 74, "12345678A", "jose@mail.com", false};
    Person marta = {"Marta", 51, "12345678A", "marta@mail.com", false};
    Person claudia = {"Claudia", 8, "12345678A", "claudia@mail.com", false};

    // Vector de estructuras personas
    vector<Person> personas{alberto, juan, jose, marta, claudia};
\
    // Creamos punteros a personas
    shared_ptr<Person> p1 = make_shared<Person>(alberto);
    shared_ptr<Person> p2 = make_shared<Person>(juan);
    shared_ptr<Person> p3 = make_shared<Person>(jose);
    shared_ptr<Person> p4 = make_shared<Person>(marta);
    shared_ptr<Person> p5 = make_shared<Person>(claudia);

    // Vector de punteros a estructuras personas
    vector<shared_ptr<Person>> ppersonas{p1, p2, p3, p4, p5};










    vector<shared_ptr<Person>> ppersonas_adultas = personas_adultas(ppersonas);

    for (auto p : ppersonas)
    {
        cout << "Nombre: " << p->name << " es adulto?: " << p->esAdulto << endl;
    }


    return 0;
}