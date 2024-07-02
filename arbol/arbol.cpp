#include "arbol.h"

/*
P_Node push(P_Node &head, int data)
{
    if (!head)
    {
        head = make_shared<Node>(Node{data, nullptr, nullptr}); // Esto ocurre en cada hijo que no tiene hijos (se crea un nuevo nodo con el valor data)
        return head;
    }
    if (data < head->data)
    {
        head->left = push(head->left, data);
        return head;
    }
    else
    {
        head->right = push(head->right, data);
        return head;
    }
}
*/

P_Node push_by_value(P_Node &head, shared_ptr<Data> &data)
{
    if (!head)
    {
        head = make_shared<Node>(Node{data, nullptr, nullptr}); // Esto ocurre en cada hijo que no tiene hijos (se crea un nuevo nodo con el valor data)
        return head;
    }
    if (data->value < head->data->value)
    {
        head->left = push_by_value(head->left, data);
        return head;
    }
    else
    {
        head->right = push_by_value(head->right, data);
        return head;
    }
}

P_Node push_by_id(P_Node &head, shared_ptr<Data> &data)
{
    if (!head)
    {
        head = make_shared<Node>(Node{data, nullptr, nullptr}); // Esto ocurre en cada hijo que no tiene hijos (se crea un nuevo nodo con el valor data)
        return head;
    }
    if (data->id < head->data->id)
    {
        head->left = push_by_value(head->left, data);
        return head;
    }
    else
    {
        head->right = push_by_value(head->right, data);
        return head;
    }
}

/*
P_Node find(P_Node &head, int data)
{
    if (!head)
    {
        return nullptr;
    }
    if ((head->data) == data) // Si soy yo, devuelvo mi cabecera
    {
        return head;
    }
    if ((head->data) > data) // Si soy mayor, busco a la izquierda
    {
        return find(head->left, data);
    }
    else // Si soy menor, busco a la derecha
    {
        return find(head->right, data);
    }
    
}
*/

P_Node find_by_value(P_Node &head, shared_ptr<Data> data)
{
    if (!head)
    {
        return nullptr;
    }
    if ((head->data->value) == data->value) // Si soy yo, devuelvo mi cabecera
    {
        return head;
    }
    if ((head->data->value) > data->value) // Si soy mayor, busco a la izquierda
    {
        return find_by_value(head->left, data);
    }
    else // Si soy menor, busco a la derecha
    {
        return find_by_value(head->right, data);
    }
    
}

P_Node find_by_id(P_Node &head, shared_ptr<Data> data)
{
    if (!head)
    {
        return nullptr;
    }
    if ((head->data->id) == data->id) // Si soy yo, devuelvo mi cabecera
    {
        return head;
    }
    if ((head->data->id) > data->id) // Si soy mayor, busco a la izquierda
    {
        return find_by_id(head->left, data);
    }
    else // Si soy menor, busco a la derecha
    {
        return find_by_id(head->right, data);
    }
    
}