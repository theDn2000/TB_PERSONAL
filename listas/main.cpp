#include <memory>
#include <iostream>
#include <functional>
#include <string>
#include <chrono>

using namespace std;

struct Person
{
    string name;
    string telephone;
};

string create_random_id()
{
    string id;
    for (int i{0}; i < 10; i++)
    {
        id += to_string(rand() % 10);
    }
    return id;
}

template <typename T>
struct Node
{
    T data;
    shared_ptr<Node<T>> next;
    string id;
};

template <typename T>
using Node_T = shared_ptr<Node<T>>;

template <typename T>
void push(Node_T<T> first, T data) // T como tipo T porque en la definición de la función se define el tipo de dato
{
    auto it = first;
    while (it->next)
    {
        it = it->next;
    }
    shared_ptr<Node<T>> new_node = make_shared<Node<T>>(Node<T>{data, nullptr, create_random_id()});
    it->next = new_node;
}

template <typename T>
shared_ptr<Node<T>> push_r(shared_ptr<Node<T>> first, T data)
{
    if (first->next)
    {
        return push_r(first->next, data);
    }
    shared_ptr<Node<T>> nNode = make_shared<Node<T>>(Node<T>{data, nullptr, create_random_id()});
    first->next = nNode;
    return nNode;
}



// Mostrar todos los datos [iterativo]
void imprimir_elem(Node_T<int> first)
{
    auto it = first;
    while (it)
    {
        cout << it->data <<  endl;
        it = it->next;
    }
}

// Mostrar todos los datos [recursivo]
void imprimir_recursivo(Node_T<int> first)
{
    if (first)
    {
        cout << first->data << endl;
        imprimir_recursivo(first->next);
    }
}

template <typename T>
void imprimir_for_each(Node_T<T> first, function<void(T)> f)
{
    auto it = first;
    while (it)
    {
        f(it->data);
        it = it->next;
    }
}

// Eliminar un elemento de la lista
template <typename T>
void eliminar_elem(Node_T<T> &first, Node_T<T> &elem)
{
    if (first != elem)
    {
        auto it = first;
        while (it->next != elem)
        {
            if (it->next == nullptr)
            {
                return;
            }
            it = it->next;
        }
        it->next = elem->next;
    }
    else
    {
        first = first->next;
    }
}

template <typename T>
void remove(Node_T<T> &head, string const &id)
{
    if (head->id == id)
    {
        head = head->next;
    }

    auto it = head;
    while (it->next->id != id)
    {
        it = it->next;
        if (it->next == nullptr)
        {
            return;
        }
    }
    it->next = it->next->next;
}



// Buscar un elemento de la lista
vector<shared_ptr<Node<Person>>> find_persons(Node_T<Person> first, string name)
{
    vector<shared_ptr<Node<Person>>> v;
    auto it = first;
    while (it)
    {
        if (it->data.name.find(name) != string::npos)
        {
            v.push_back(it);
        }
        it = it->next;
    }
    return v;
}

int main()
{
    shared_ptr<Node<Person>> start = make_shared<Node<Person>>(Node<Person>{Person{"Dani", "666666666"}, nullptr, create_random_id()});
    // shared_ptr<Node<int>> other = make_shared<Node<int>>(Node<int>{2, nullptr});
    // shared_ptr<Node<int>> other3 = make_shared<Node<int>>(Node<int>{3, nullptr});

    push(start, Person{"Pepe", "777777777"});
    push(start, Person{"Jose", "888888888"});
    push(start, Person{"Rodri", "999999999"});

    while (true)
    // Wait 1 second


    {
        // Agenda [añadir, eliminar, buscar, mostrar]

        // Se pregunta al usuario que quiere hacer
        cout << "Bienvenido a la mejor agenda del mundo" << endl;
        cout << "1. Añadir contacto" << endl;
        cout << "2. Eliminar contacto" << endl;
        cout << "3. Buscar contacto" << endl;
        cout << "4. Mostrar todos los contactos" << endl
             << endl;
        cout << "¿Qué quieres hacer?: ";

        int option;
        cin >> option;

        switch (option)
        {
        case 1:
        {
            string name;
            string telephone;
            cout << "Nombre: ";
            cin >> name;
            cout << "Telefono: ";
            cin >> telephone;
            push(start, Person{name, telephone});
            cout << "Contacto añadido correctamente" << endl << endl;
            break;
        }
        case 2:
        {
            string id;
            // Muestra todos los contactos y sus id
            auto it = start;
            while (it)
            {
                cout << it->data.name << " " << it->data.telephone << " " << it->id << endl;
                it = it->next;
            }
            cout << "Introduce la id del contacto que quieres eliminar: ";
            cin >> id;
            remove(start, id);
            cout << "Contactro eliminado correctamente" << endl << endl;
            break;
        }
        case 3:
        {
            string name;
            cout << "Introduce el nombre: ";
            cin >> name;
            auto v = find_persons(start, name);
            for (auto elem : v)
            {
                cout << elem->data.name << " " << elem->data.telephone << endl;
            }
            cout << endl;
            break;
        }
        case 4:
        {
            imprimir_for_each<Person>(start, [](Person p)
                                      { cout << p.name << " " << p.telephone << endl << endl;});
            break;
        }
        default:
        {
            cout << "Por favor, selecciona una de las opciones posibles" << endl << endl;
            break;
        }
        }
    }

    /*
    // Imprimir_elem
    //imprimir_elem(start);

    // Eliminar_elem
    //eliminar_elem(start, start->next);

    // Imprimir_recursivo
    //imprimir_recursivo(start);

    // Imprimir_for_each
    imprimir_for_each(start, [](int a)
    {
        cout << a << endl;
    }
    );
    */
}