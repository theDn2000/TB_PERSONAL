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

P_Node push(P_Node &head, Data data)
{
    if (!head)
    {
        head = make_shared<Node>(Node{data, nullptr, nullptr}); // Esto ocurre en cada hijo que no tiene hijos (se crea un nuevo nodo con el valor data)
        return head;
    }
    if (data.id < head->data.id)
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

P_Node find(P_Node &head, Data data)
{
    if (!head)
    {
        return nullptr;
    }
    if ((head->data.id) == data.id) // Si soy yo, devuelvo mi cabecera
    {
        return head;
    }
    if ((head->data.id) > data.id) // Si soy mayor, busco a la izquierda
    {
        return find(head->left, data);
    }
    else // Si soy menor, busco a la derecha
    {
        return find(head->right, data);
    }
    
}