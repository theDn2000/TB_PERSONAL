#include "lista.h"
using P_Node = shared_ptr<Node>;


string create_random_id()
{
    string id;
    for (int i{0}; i < 10; i++)
    {
        id += to_string(rand() % 10);
    }
    return id;
}

P_Node push_back(P_Node const & head, int data)
{
    if (!head)
    {
        P_Node new_node = make_shared<Node>(Node{create_random_id(), data, nullptr, nullptr});
        return new_node;
    }
    auto it = head;
    while (it->next)
    {
        it = it->next;
    }

    P_Node new_node = make_shared<Node>(Node{create_random_id(), data, nullptr, it});
    it->next = new_node;
    return head;
}

P_Node push_front(P_Node const & head, int data)
{
    if (!head)
    {
        P_Node new_node = make_shared<Node>(Node{create_random_id(), data, nullptr, nullptr});
        return new_node;
    }

    P_Node new_node = make_shared<Node>(Node{create_random_id(), data, head, nullptr});
    return new_node;
}

P_Node push_at(P_Node const & head, int data, int pos)
{
    // Control de errores

    // Sabemos que hay head y que la pos > 0
    auto it = head;
    int index{0};

    while (it->next)
    {
        index++;
        it = it->next;
        if (pos==index)
        {
            P_Node new_node = make_shared<Node>(Node{create_random_id(), data, it, it->prev});
            it->prev->next = new_node;
            it->prev = new_node;
            return head;
        }
    }
    throw std::out_of_range("Invalid position. Greater than list");
}

P_Node push_in_order(P_Node const & head, int data, bool asc = true)
{
    if (!head)
    {
        P_Node new_node = make_shared<Node>(Node{create_random_id(), data, nullptr, nullptr});
        return new_node;
    }

    auto it = head;
    while (it->next)
    {
        auto condition = asc ? it->next->data < data : it->next->data > data;

        if (condition)
        {
            it = it->next;
        }
        else
        {
            P_Node new_node = make_shared<Node>(Node{create_random_id(), data, it, it->prev});
            it->prev->next = new_node;
            it->prev = new_node;
            return head;
        }
    }
    push_back(head, data);
    return head;

}

P_Node pop_front(P_Node const & head)
{
    if (!head) // No hay primero
    {
        return nullptr;
    }
    else if (!head->next) // Sólo hay primero
    {
        return nullptr;
    }
    else
    {
        head->next->prev = nullptr;
        // return it
        return head->next;
    }
}

P_Node pop_back(P_Node const & head)
{
    if (!head) // No hay primero
    {
        return nullptr;
    }
    else if (!head->next) // Sólo hay primero
    {
        return nullptr;
    }
    else
    {
        auto it = head;
        while(it->next)
        {
            it = it->next;
        }
        it->prev->next = nullptr;
        // return it
        return  it->prev;
    }
}