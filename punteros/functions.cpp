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