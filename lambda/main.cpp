#include <functional>
#include <iostream>
#include <vector>

using namespace std;

// Alias
typedef vector<int> vi;
typedef function<void(int)> flambda;

int operacion(int a, int b, function<int(int,int)> f)
{
    return f(a,b);
}

// For Each --> Recorre un vector y hace algo con cada elemento
void forEach(vi const &v, flambda const &f)
{
    for (auto elem : v)
    {
        f(elem);
    }
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


    flambda print = [](int a)
    {
        cout << a << endl;
    };

    flambda print_if_even = [](int a)
    {
        if (a % 2 == 0)
        {
            cout << a << endl;
        }
    };

    vi v = {1, 2, 3, 4, 5};

    forEach(v, print_if_even);

    /*
    auto h = operacion(1, 2, suma); // Función lambda o funcion de callback
    auto m = operacion(1, 2, multiplicacion);

    cout << "Suma: " << h << endl;
    cout << "Multiplicación: " << m << endl;
    */
    return 0;
}