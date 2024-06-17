#include <memory>
#include <iostream>

using namespace std;

void modifica(int x)
{
    x = 11;
}
void modificaP(shared_ptr<int> pX)
{
    *pX = 11;
}

int sumaa(int a, int b)
{
    return a + b;
}

int sumaaP(shared_ptr<int> pA, shared_ptr<int> pB)
{
    return *pA + *pB;
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

    int ab = sumaa(a, b);
    int pApB = sumaaP(pA, pB);

    cout << "a + b: " << ab << endl;
    cout << "pA + pB: " << pApB << endl;

    return 0;
}