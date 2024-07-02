#pragma once

#include <iostream>
#include <memory>
#include <functional>
#include <random>

using namespace std;

struct Node;

using P_Node = shared_ptr<Node>;

struct Data
{
    int value;
    int id;
    string name;
};

struct Node
{
    shared_ptr<Data> data;
    shared_ptr<Node> left;
    shared_ptr<Node> right;
};


template<typename T>
P_Node push(P_Node &head, shared_ptr<Data> &data, function<T(shared_ptr<Data>)> f)
{
    if (!head)
    {
        head = make_shared<Node>(Node{data, nullptr, nullptr}); // Esto ocurre en cada hijo que no tiene hijos (se crea un nuevo nodo con el valor data)
        return head;
    }
    if (f(data) < f(head->data))
    {
        head->left = push(head->left, data, f);
        return head;
    }
    else
    {
        head->right = push(head->right, data, f);
        return head;
    }
}

template<typename T>
P_Node find(P_Node &head, shared_ptr<Data> &data, function<T(shared_ptr<Data>)> f)
{
    if (!head)
    {
        return nullptr;
    }
    if (f(head->data) == f(data)) // Si soy yo, devuelvo mi cabecera
    {
        return head;
    }
    if (f(head->data) > f(data)) // Si soy mayor, busco a la izquierda
    {
        return find(head->left, data, f);
    }
    else // Si soy menor, busco a la derecha
    {
        return find(head->right, data, f);
    }
}