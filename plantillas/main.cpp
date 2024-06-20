#include <iostream>
#include <vector>
#include <functional>
#include <memory>


using namespace std;

// Struct person
struct Person
{
    string name;
    int age;
};

// Templatizar 
template <typename T>
T suma (T a, T b)
{
    return a + b;
}

// Templatizar varios tipos de datos
template <typename T, typename U>
T pipo(T a, U b)
{
    return a + b;
}

Person suma (Person a, Person b)
{
    Person p;
    p.name = a.name + b.name;
    p.age = a.age + b.age;
    return p;
}

// Templatizar for each
template <typename T, typename U>
void forEach(vector<T> const &v, function<U(T)> const &f)
{
    for (auto elem : v)
    {
        f(elem);
    }
};


int main ()
{
    // Plantillas: Funciones a las que no les queremos especificar el tipo de dato
    auto c = suma<int>(5, 6);
    return 0;

    vector<int> v = {1, 2, 3, 4, 5};
    forEach<int, void>(v, [](int elem) 
    { 
        cout << elem << endl; 
    });
}