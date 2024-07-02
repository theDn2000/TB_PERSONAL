#include "arbol.h"

int uuid()
{
    // Genera un id aleatorio de 4 caracteres
    return rand() % 10000;
}

int main()
{
    P_Node head = nullptr;
    Data d1 = {10, uuid()};
    Data d2 = {5, uuid()};
    Data d3 = {11, uuid()};
    Data d4 = {6, uuid()};

    push(head, d1);
    push(head, d2);
    push(head, d3);
    push(head, d4);

    cout << "Searching for: " << d2.id << endl;
    P_Node found = find(head, d2);
    // Print the value of the found data struct
    cout << found->data.value << endl;

    /*
    push(head, 10);
    push(head, 5);
    push(head, 11);
    push(head, 6);
    */
    return 0;

    // Ordenar y buscar por referencia, mostrar su valor.

    /*
    head->data = 10;
    head->left->data = 5;
    head->right->data = 11;
    head->left->right->data = 6;
    head->right->left = nullptr;
    head->right->right = nullptr;
    */
}