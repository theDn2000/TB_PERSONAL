#include <memory>
#include <iostream>
#include <functional>
#include <string>
#include <chrono>
#include <fstream>
#include <sstream>

using namespace std;

struct Person
{
    string name;
    string telephone;
};

bool operator<(Person const &p1, Person const &p2)
{
    return p1.name < p2.name;
}

bool operator==(Person const &p1, Person const &p2)
{
    return p1.name == p2.name;
}

bool operator >(Person const &p1, Person const &p2)
{
    return p1.name > p2.name;
}

ostream &operator<< (ostream &os, Person const &p)
{
    os << p.name << " " << p.telephone;
    return os;
}

istream &operator>> (istream &is, Person &p)
{
    is >> p.name >> p.telephone;
    return is;
}

struct Matrix
{
    int rows;
    int cols;
    vector<vector<int>> data;
};

ostream &operator<< (ostream &os, Matrix const &m)
{
    if (typeid(os) == typeid(ofstream)) // Lo estamos escribiendo en un archivo
    {
        for (int i{0}; i < m.rows; i++)
        {
            for (int j{0}; j < m.cols; j++)
            {
                os << m.data[i][j] << " ";
            }
        }
    }
    else
    {
        //os << "[";
        for (int i{0}; i < m.rows; i++)
        {
            for (int j{0}; j < m.cols; j++)
            {
                os << m.data[i][j] << " ";
            }
            os << endl;
        }
        //os << "]";
    }
    return os;
}

istream &operator>> (istream &is, Matrix &m)
{
    cout << "Introduce el numero de filas: ";
    is >> m.rows;
    cout << "Introduce el numero de columnas: ";
    is >> m.cols;
    m.data = vector<vector<int>>(m.rows, vector<int>(m.cols));
    for (int i{0}; i < m.rows; i++)
    {
        for (int j{0}; j < m.cols; j++)
        {
            cout << "Introduce el valor de la fila " << i << " columna " << j << ": ";
            is >> m.data[i][j];
        }
    }
    return is;
}

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
void push(Node_T<T> first, T data, bool inOrder = false) // T como tipo T porque en la definición de la función se define el tipo de dato
{
    if (inOrder)
    {
        auto it = first;
        while (it->next)
        {
            if (it->next->data < data)
            {
                it = it->next;
            }
            else
            {
                shared_ptr<Node<T>> new_node = make_shared<Node<T>>(Node<T>{data, it->next, create_random_id()});
                it->next = new_node;
                return;
            }
        }
    }
    else
    {
        auto it = first;
        while (it->next)
        {
            it = it->next;
        }
        shared_ptr<Node<T>> new_node = make_shared<Node<T>>(Node<T>{data, nullptr, create_random_id()});
        it->next = new_node;
    }

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
    /*
    // EJERCICIO PERSONA
    vector<Person> v;
    
    // Número de personas a añadir
    cout << "Cuantas personas quieres añadir?: ";
    int n;
    cin >> n;

    // Añade personas
    for (int i{0}; i < n; i++)
    {
        Person p;
        cin >> p; 
        v.push_back(p);
    }

    // Guarda las personas en un archivo
    ofstream archivoPersonas("personas.txt");
    if (!archivoPersonas)
    {
        cout << "Error al crear el archivo" << endl;
        return 1;
    }
    for (auto elem : v)
    {
        archivoPersonas << elem << endl;
    }
    archivoPersonas.close();

    // Muestra las personas en la terminal
    ifstream archivoPersonasLectura("personas.txt");
    std::string line;

    cout << endl << "Personas en el archivo: " << endl;
    while(getline(archivoPersonasLectura, line))
    {
        cout << line << endl;
    }

    archivoPersonasLectura.close();
    */



    /*
    // EJERCICIO MATRIZ
    // Inicializa la matriz
    Matrix m{0, 0, vector<vector<int>>()}; // Realmente es mejor guardarlo como un array y luego separar

    // Rellena la matriz
    cin >> m;

    // Muestra la matriz en la terminal
    cout << endl << m << endl;


    // Guarda la matriz en un archivo
    ofstream archivoMatriz("matriz.txt");
    if (!archivoMatriz)
    {
        cout << "Error al crear el archivo" << endl;
        return 1;
    }
    archivoMatriz << m;

    archivoMatriz.close();

    // Lee el archivo y muestra la matriz en la terminal
    ifstream archivoMatrizLectura("matriz.txt");
    std::string line;

    while(getline(archivoMatrizLectura, line))
    {
        cout << line << endl;
    }

    archivoMatrizLectura.close();
    */





    // AGENDA
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
        cout << "4. Mostrar todos los contactos" << endl;
        cout << "5. Guardar en archivo" << endl;
        cout << "6. Importar contactos desde archivo" << endl;
        cout << "7. Salir"
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
            cout << endl << "Introduce la id del contacto que quieres eliminar: ";
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
                                      { cout << p.name << " " << p.telephone << endl;});
            cout << endl;
            break;
        }
        case 5:
        {
            ofstream archivoPersonas("personas.txt",ios::app);
            if (!archivoPersonas)
            {
                cout << "Error al crear el archivo" << endl;
                return 1;
            }
            cout << "Guardando en archivo..." << endl;
            imprimir_for_each<Person>(start, [&archivoPersonas](Person p)
            {
                archivoPersonas << p;
                archivoPersonas << endl;
            });
            archivoPersonas.close();
            break;
        }
        case 6:
        {
            ifstream archivoPersonasLectura("personas.txt");
            std::string line;
            Person p;

            while(getline(archivoPersonasLectura, line))
            {
                istringstream is(line);
                is >> p;
                push(start, p);
            }
            archivoPersonasLectura.close();
            break;
        }
        case 7:
        {
            return 0;
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