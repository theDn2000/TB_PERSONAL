#include <functional>
#include <iostream>
#include <vector>

using namespace std;

// Alias
typedef vector<int> vi;
typedef function<void(int)> flambda;

int operacion(int a, int b, function<int(int, int)> f)
{
    return f(a, b);
}

// For Each --> Recorre un vector y hace algo con cada elemento
void forEach(vi const &v, flambda const &f)
{
    for (auto elem : v)
    {
        f(elem);
    }
}

// Some --> Recibe un vector y una funcion lambda y devuelve true si algun elemento del vector cumple el requisito de la funcion lambda
bool some(vi const &v, function<bool(int)> const &f)
{
    bool is_greater = false;
    for (auto elem : v)
    {
        if (f(elem))
        {
            is_greater = true;
        }
    }
    return is_greater;
}

int main()
{
    function<int(int, int)> suma = [](int a, int b)
    {
        return a + b;
    };

    function<int(int, int)> resta = [](int a, int b)
    {
        return a - b;
    };

    function<int(int, int)> multiplicacion = [](int a, int b)
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

    function<bool(int)> is_greater_than_10 = [](int a)
    {
        if (a > 10)
        {
            return true;
        }
        else
        {
            return false;
        }
    };

    vi v = {1, 2, 3, 4, 5, 14};

    bool is_greater = some(v, is_greater_than_10);
    cout << is_greater << endl;

    /*
    auto h = operacion(1, 2, suma); // Función lambda o funcion de callback
    auto m = operacion(1, 2, multiplicacion);

    cout << "Suma: " << h << endl;
    cout << "Multiplicación: " << m << endl;
    */
    return 0;
}