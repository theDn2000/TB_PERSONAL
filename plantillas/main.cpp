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
template <typename T>
void forEach(vector<T> const &v, function<void(T)> const &f)
{
    for (auto elem : v)
    {
        f(elem);
    }
};

// Templatizar some
template <typename T>
bool some(vector<T> const &v, function<bool(T)> const &f)
{
    for (auto elem : v)
    {
        if (f(elem))
        {
            return true;
        }
    }
    return false;
}

// Templatizar every
template <typename T>
bool every(vector<T> const &v, function<bool(T)> const &f)
{
    for (auto elem : v)
    {
        if (!f(elem))
        {
            return false;
        }
    }
    return true;
}

// Templatizar operacion
template <typename T>
vector<T> filter (vector<T> const &v, function<bool(T)> const &f)
{
    vector<T> result;
    for (auto elem : v)
    {
        if (f(elem))
        {
            result.push_back(elem);
        }
    }
    return result;
}

// Templatizar transform
template <typename T>
vector<T> transform (vector<T> const &v, function<T(T)> const &f)
{
    vector<T> result;
    for (T elem : v)
    {
        result.push_back(f(elem));
    }
    return result;
}

// Templatizar find
template <typename T>
T find (vector<T> const &v, function<bool(T)> const &f)
{
    for (auto elem : v)
    {
        if (f(elem))
        {
            return elem;
        }
    }
    // Return null
    return T();
}


int main ()
{
    // Plantillas: Funciones a las que no les queremos especificar el tipo de dato
    auto c = suma<int>(5, 6);
    

    vector<int> v = {1, 2, 3, 4, 5};
    vector<Person> vp = {{"Juan", 20}, {"Pedro", 30}};
    forEach<Person>(vp, [](Person elem) 
    { 
        cout << elem.name << endl; 
    });

    bool result = some<Person>(vp, [](Person elem) 
    { 
        return elem.age > 25; 
    });

    bool result2 = every<Person>(vp, [](Person elem) 
    { 
        return elem.age > 25; 
    });

    vector<Person> result3 = filter<Person>(vp, [](Person elem) 
    { 
        return elem.age > 25; 
    });

    Person result4 = transform<Person>(vp, [](Person elem) 
    { 
        elem.age += 10;
        return elem;
    });

    Person result5 = find<Person>(vp, [](Person elem) 
    { 
        return elem.age > 25; 
    });
    

    return 0;
}