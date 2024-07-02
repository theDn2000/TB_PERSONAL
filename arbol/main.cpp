#include "arbol.h"

int uuid()
{
    // Genera un id aleatorio de 4 caracteres
    return rand() % 10000;
}

struct Aux
{
    int value;
    string name;
};

bool operator==(Aux const &a1, Aux const &a2)
{
    return (a1.value == a2.value && a1.name == a2.name);
}

bool operator<(Aux const &a1, Aux const &a2)
{
    return a1.value < a2.value;
}

bool operator>(Aux const &a1, Aux const &a2)
{
    return a1.value > a2.value;
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

    P_Node head3 = nullptr;
    push<Aux>(head3, d1_ptr, [](shared_ptr<Data> d) { return Aux{d->value, d->name}; });
    push<Aux>(head3, d2_ptr, [](shared_ptr<Data> d) { return Aux{d->value, d->name}; });
    push<Aux>(head3, d3_ptr, [](shared_ptr<Data> d) { return Aux{d->value, d->name}; });
    push<Aux>(head3, d4_ptr, [](shared_ptr<Data> d) { return Aux{d->value, d->name}; });



    cout << "Searching for id: " << d2.id << endl;
    P_Node found = find<Aux>(head3, d2_ptr, [](shared_ptr<Data> d) { return Aux{d->value, d->name}; });
    // Print the name of the found data struct
    cout << found->data->name<< endl;

    cout << endl;

    cout << "Changing name of found data struct" << endl;
    found->data->name = "Robertito";
    cout << endl;

    cout << "Searching for id: " << d2.id << endl;
    P_Node found3 = find<Aux>(head3, d2_ptr, [](shared_ptr<Data> d) { return Aux{d->value, d->name}; });
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