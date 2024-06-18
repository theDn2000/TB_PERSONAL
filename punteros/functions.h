#pragma once

#include <iostream>
#include <vector>
#include <string>

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

