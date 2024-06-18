#include "functions.h"
#include <stdexcept>

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int sumaa(int a, int b)
{
    return a + b;
}

int sumaaP(shared_ptr<int> pA, shared_ptr<int> pB)
{
    return *pA + *pB;
}

// Punteros
bool include(vector<shared_ptr<Person>> const &personas, shared_ptr<Person> const &p)
{
    for (auto const &persona : personas)
    {
        if (persona == p)
        {
            return true;
        }
    }
    return false;
}

// Sobre carga de funciones, mismo nombre, diferentes parámetros
bool include(vector<shared_ptr<Person>> const &personas, vector<shared_ptr<Person>> const &personas2)
{
    for (auto const &p: personas2)
    {
        if (include(personas, p)!=true) 
        {
            return false;
        }
    }
    return true;
}

// Intersección
vector<shared_ptr<Person>> intersection(vector<shared_ptr<Person>> const &personas, vector<shared_ptr<Person>> const &personas2)
{
    vector<shared_ptr<Person>> interseccion;
    for (auto const &p: personas)
    {
        if (include(personas2, p))
        {
            interseccion.push_back(p);
        }
    }
    return interseccion;
}

// Unión
vector<shared_ptr<Person>> unity(vector<shared_ptr<Person>> const &personas, vector<shared_ptr<Person>> const &personas2)
{
    vector<shared_ptr<Person>> union_vector = personas;
    for (auto const &p : personas2)
    {
        if (include(union_vector, p) != true)
        {
            union_vector.push_back(p);
        }
    }
    return union_vector;
}

// Diferencia
vector<shared_ptr<Person>> difference(vector<shared_ptr<Person>> const &personas, vector<shared_ptr<Person>> const &personas2)
{
    vector<shared_ptr<Person>> diferencia_vector;
    for (auto const &p : personas2)
    {
        if (include(personas, p) != true)
        {
            diferencia_vector.push_back(p);
        }
    }
    return diferencia_vector;
}
