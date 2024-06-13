#include "functions.h"
#include <stdexcept>

// Tests y test driven development
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