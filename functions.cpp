#include "functions.h"
#include <stdexcept>

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Tests y test driven development

// Suma
int suma (int a, int b)
{
    return a + b;
}

int sumaP(int a, int b)
{
    if (a + b < 0)
    {
        throw std::runtime_error("Resultado negativo");
    }
    return a + b;
}

// Función parsea string
vector<string> separate_string(string & s)
{
    // Separa por contenido entre parentesis, por nivel: "((hola) (soy) (dani)) (que tal) (estas)" -> {(hola) (soy) (dani), que tal, estas}
    vector<string> v;
    int pos{0};
    int level{0};
    string temp;
    // Compruebo que empieza con parentesis
    if (s[0] != '(')
    {
        throw std::runtime_error("No empieza con parentesis");
    }
    // Compruebo que termina con parentesis
    if (s[s.size()-1] != ')')
    {
        throw std::runtime_error("No termina con parentesis");
    }
    // Comprueba que no haya paréntesis sin ningún carácter dentro
    if (s[pos] == '(' && s[pos+1] == ')')
    {
        throw std::runtime_error("Parentesis vacio");
    }

    while (pos < s.size())
    {
        if (s[pos] == '(')
        {
            level++;
        }
        else if (s[pos] == ')')
        {
            level--;
        }

        // Dependiendo del nivel, se añade al vector o se reinicia el string temporal
        if (s[pos] == '(' && level == 1)
        {
            temp = "";
        }
        else if (s[pos] == ')' && level == 0)
        {
            v.push_back(temp);
        }
        else
        {
            // Comprueba que no hay palabras sin parentesis
            if (level == 0 && s[pos] != ' ')
            {
                throw std::runtime_error("Palabra sin parentesis");
            }
            else
            {
                temp += s[pos];
            }
        }
        pos++;
    }
    
    // Compruebo que se han abierto y cerrado los mismos parentesis
    if (level != 0)
    {
        throw std::runtime_error("No se han abierto y cerrado los mismos parentesis");
    }
    else
    {
        return v;
    }
}