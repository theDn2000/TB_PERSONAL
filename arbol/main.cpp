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
    shared_ptr<Data> d1_ptr = make_shared<Data>(d1);
    Data d2 = {5, uuid(), "Roberto"};
    shared_ptr<Data> d2_ptr = make_shared<Data>(d2);
    Data d3 = {11, uuid(), "Paula"};
    shared_ptr<Data> d3_ptr = make_shared<Data>(d3);
    Data d4 = {6, uuid(), "Pedro"};
    shared_ptr<Data> d4_ptr = make_shared<Data>(d4);

    push<int>(head, d1_ptr, [](shared_ptr<Data> d) { return d->id; });
    push<int>(head, d2_ptr, [](shared_ptr<Data> d) { return d->id; });
    push<int>(head, d3_ptr, [](shared_ptr<Data> d) { return d->id; });
    push<int>(head, d4_ptr, [](shared_ptr<Data> d) { return d->id; });

    // Crear arbol #2
    P_Node head2 = nullptr;
    push<int>(head2, d1_ptr, [](shared_ptr<Data> d) { return d->value; });
    push<int>(head2, d2_ptr, [](shared_ptr<Data> d) { return d->value; });
    push<int>(head2, d3_ptr, [](shared_ptr<Data> d) { return d->value; });
    push<int>(head2, d4_ptr, [](shared_ptr<Data> d) { return d->value; });



    cout << "Searching for id: " << d2.id << endl;
    P_Node found = find<int>(head, d2_ptr, [](shared_ptr<Data> d) { return d->id; });
    // Print the name of the found data struct
    cout << found->data->name<< endl;

    cout << endl;
    cout << "Searching for value: " << d2.value << endl;
    P_Node found2 = find<int>(head, d2_ptr, [](shared_ptr<Data> d) { return d->value; });
    // Print the name of the found data struct
    cout << found2->data->name<< endl;
    cout << endl;

    cout << "Changing name of found data struct" << endl;
    found2->data->name = "Robertito";
    cout << endl;

    cout << "Searching for id: " << d2.id << endl;
    P_Node found3 = find<int>(head, d2_ptr, [](shared_ptr<Data> d) { return d->id; });
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