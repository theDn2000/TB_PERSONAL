#include "arbol.h"

struct Data
{
    int value;
    int id;
};

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

    push(head, d1.id);
    push(head, d2.id);
    push(head, d3.id);
    push(head, d4.id);

    cout << "Searching for: " << d2.id << endl;
    P_Node found = find(head, d2.id);
    cout << "Found: " << found->data << endl;
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