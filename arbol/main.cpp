#include "arbol.h"



int main()
{
    P_Node head = nullptr;
    push(head, 10);
    push(head, 5);
    push(head, 11);
    push(head, 6);
    return 0;

    /*
    head->data = 10;
    head->left->data = 5;
    head->right->data = 11;
    head->left->right->data = 6;
    head->right->left = nullptr;
    head->right->right = nullptr;
    */
}