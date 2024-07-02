#include "arbol.h"

int uuid()
{
    // Genera un id aleatorio de 4 caracteres
    return rand() % 10000;
}

int main()
{
    // Crear arbol #1
    P_Node head = nullptr;
    Data d1 = {10, uuid(), "Mireia"};
    Data d2 = {5, uuid(), "Roberto"};
    Data d3 = {11, uuid(), "Paula"};
    Data d4 = {6, uuid(), "Pedro"};

    push_by_value(head, d1);
    push_by_value(head, d2);
    push_by_value(head, d3);
    push_by_value(head, d4);

    // Crear arbol #2
    P_Node head2 = nullptr;
    push_by_id(head2, d1);
    push_by_id(head2, d2);
    push_by_id(head2, d3);
    push_by_id(head2, d4);



    cout << "Searching for id: " << d2.id << endl;
    P_Node found = find_by_id(head, d2);
    // Print the name of the found data struct
    cout << found->data->name<< endl;

    cout << endl;
    cout << "Searching for value: " << d2.value << endl;
    P_Node found2 = find_by_value(head, d2);
    // Print the name of the found data struct
    cout << found2->data->name<< endl;
    cout << endl;

    cout << "Changing name of found data struct" << endl;
    found2->data->name = "Robertito";
    cout << endl;

    cout << "Searching for id: " << d2.id << endl;
    P_Node found3 = find_by_id(head, d2);
    // Print the name of the found data struct
    cout << found3->data->name<< endl;

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