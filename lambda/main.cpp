#include <functional>
#include <iostream>
#include <vector>
#include <memory>

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

// Alias
typedef vector<int> vi;
typedef function<void(int)> flambda;
typedef vector<shared_ptr<Person>> vpp;
typedef function<bool(shared_ptr<Person>)> fpp;

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
bool some(vpp const &v, fpp const &f)
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

// Every --> Recibe un vector y una funcion lambda y devuelve true si todos los elementos del vector cumplen el requisito de la funcion lambda
bool every(vpp const &v, fpp const &f)
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

// Filter --> Recibe un vector y una funcion lambda y devuelve un vector con los elementos que cumplen el requisito de la funcion lambda
vector<int> filter (vi const &v, function<bool(int)> const &f)
{
    vi result;
    for (auto elem : v)
    {
        if (f(elem))
        {
            result.push_back(elem);
        }
    }
    return result;
}

// Transform --> Recibe un vector y una funcion lambda y devuelve un vector con los elementos transformados por la funcion lambda
vpp transform (vpp const &v, function<shared_ptr<Person>(shared_ptr<Person>)> const &f)
{
    vpp result;
    for (auto elem : v)
    {
        shared_ptr<Person> p = make_shared<Person>(*elem);
        result.push_back(f(p));
    }
    return result;
}

// Find --> Recibe un vector y una funcion lambda y devuelve el primer elemento que cumple el requisito de la funcion lambda
shared_ptr<Person> find (vpp const &v, function<bool(shared_ptr<Person>)> const &f)
{
    for (auto elem : v)
    {
        if (f(elem))
        {
            return elem;
        }
    }
    return nullptr;
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

    function <int(int)> square = [](int a)
    {
        return a * a;
    };

    vi v = {48, 17};

    /*
    vector<int> result = transform(v, square);
    for (auto elem : result)
    {
        cout << elem << endl;
    };
    */


    
    // Personas
    // Creamos personas
    Person alberto{"Alberto", 30, "12345678A", "alberto@mail.com", false}; // Estructuras
    Person juan = {"Juan", 15, "12345678A", "juan@mail.com", false};
    Person jose = {"Jose", 74, "12345678A", "jose@mail.com", false};
    Person marta = {"Marta", 51, "12345678A", "marta@mail.com", false};
    Person claudia = {"Claudia", 8, "12345678A", "claudia@mail.com", false};

    // Creamos punteros a personas
    shared_ptr<Person> p1 = make_shared<Person>(alberto);
    shared_ptr<Person> p2 = make_shared<Person>(juan);
    shared_ptr<Person> p3 = make_shared<Person>(jose);
    shared_ptr<Person> p4 = make_shared<Person>(marta);
    shared_ptr<Person> p5 = make_shared<Person>(claudia);
    // Hay dos juanes, con las mismas propiedades pero con distinta dirección de memoria
    shared_ptr<Person> p6 = make_shared<Person>(juan); // El otro juan

    // Vector de punteros a estructuras personas (no añadimos al otro juan)
    vector<shared_ptr<Person>> ppersonas{p1, p2, p3, p4, p5};

    // Aplicamos la funcion some al vector de punteros a personas
    bool result = some(ppersonas, [](shared_ptr<Person> p) {return p->age > 18;});
    cout << "Hay alguna persona mayor de edad?: " << result << endl;

    // Aplicamos la funcion every al vector de punteros a personas
    bool result2 = every(ppersonas, [](shared_ptr<Person> p) {return p->age > 18;});
    cout << "Son todas las personas mayores de edad: " << result2 << endl;

    // Aplicamos la funcion transform al vector de enteros
    vpp result3 = transform(ppersonas, [](shared_ptr<Person> p) {if (p->age > 18) {p->esAdulto = true;} return p;});
    cout << result3[0]->esAdulto << endl;

    // Aplicamos la funcion find al vector de punteros a personas
    shared_ptr<Person> result4 = find(ppersonas, [](shared_ptr<Person> p) {return p->age > 90;});
    if (result4 == nullptr)
    {
        cout << "No hay ninguna persona mayor de 50 en el vector" << endl;
    }
    else
    {
        cout << "Primer persona mayor de 50 en el vector: " << result4->name << endl;
    }

    /*
    auto h = operacion(1, 2, suma); // Función lambda o funcion de callback
    auto m = operacion(1, 2, multiplicacion);

    cout << "Suma: " << h << endl;
    cout << "Multiplicación: " << m << endl;
    */
    return 0;
}