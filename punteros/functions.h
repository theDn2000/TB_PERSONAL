#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

// Clase persona
struct Person
{
    string name;
    int age;
    string dni;
    string mail;
    bool esAdulto;
};

// Suma
int sumaa(int a, int b);
int sumaaP(shared_ptr<int> pA, shared_ptr<int> pB);

// Include personas
bool include(vector<shared_ptr<Person>> const &personas, shared_ptr<Person> const &p);

// Sobre carga de funciones, mismo nombre, diferentes parámetros
bool include(vector<shared_ptr<Person>> const &personas, vector<shared_ptr<Person>> const &personas2);

