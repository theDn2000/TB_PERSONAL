#include "arbol.h"

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
        return head
    }
    else
    {
        head->right = push(head->right, data);
        return head;
    }
}