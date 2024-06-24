#include <memory>
#include <iostream>
#include <functional>

using namespace std;

template <typename T>
struct Node
{
    T data;
    shared_ptr<Node<T>> next;
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
    shared_ptr<Node<T>> new_node = make_shared<Node<T>>(Node<T>{data, nullptr});
    it->next = new_node;
}

template <typename T>
shared_ptr<Node<T>> push_r(shared_ptr<Node<T>> first, T data)
{
    if (first->next)
    {
        return push_r(first->next, data);
    }
    shared_ptr<Node<T>> nNode = make_shared<Node<T>>(Node<T>{data, nullptr});
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
    cout << endl;
}

// Mostrar todos los datos [recursivo]
void imprimir_recursivo(Node_T<int> first)
{
    if (first)
    {
        cout << first->data << endl;
        imprimir_recursivo(first->next);
    }
    cout << endl;
}

void imprimir_for_each(Node_T<int> first, function<void(int)> f)
{
    auto it = first;
    while (it)
    {
        f(it->data);
        it = it->next;
    }
}












int main()
{
    shared_ptr<Node<int>> start = make_shared<Node<int>>(Node<int>{1, nullptr});
    //shared_ptr<Node<int>> other = make_shared<Node<int>>(Node<int>{2, nullptr});
    //shared_ptr<Node<int>> other3 = make_shared<Node<int>>(Node<int>{3, nullptr});

    push(start, 2);
    push(start, 3);
    push(start, 4);



    // Imprimir_elem
    imprimir_elem(start);


/*
    // Imprimir_recursivo
    imprimir_recursivo(start);

    // Imprimir_for_each
    imprimir_for_each(start, [](int a)
    {
        cout << a << endl;
    }
    );
*/
}