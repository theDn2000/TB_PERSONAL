#include <functional>
#include <iostream>

using namespace std;


int operacion(int a, int b, function<int(int,int)> f)
{
    return f(a,b);
}

int main ()
{
    function<int(int,int)> suma = [](int a, int b)
    {
        return a + b;
    };

    function<int(int,int)> resta = [](int a, int b)
    {
        return a - b;
    };

    function<int(int,int)> multiplicacion = [](int a, int b)
    {
        return a * b;
    };

    auto h = operacion(1, 2, suma); // Función lambda o funcion de callback
    auto m = operacion(1, 2, multiplicacion);

    cout << "Suma: " << h << endl;
    cout << "Multiplicación: " << m << endl;

    return 0;
}