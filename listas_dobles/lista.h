#pragma once

#include <iostream>
#include <functional>
#include <string>
#include <memory>

using namespace std;

struct Node
{
    string id;
    int data;
    P_Node next;
    P_Node prev;
};

using P_Node = shared_ptr<Node>;

string create_random_id();

P_Node push_back(P_Node const & head, int data);
P_Node push_front(P_Node const & head, int data);
P_Node push_at(P_Node const & head, int data, int pos);
P_Node push_in_order(P_Node const & head, int data, bool asc = true);

P_Node pop_front(P_Node const & head);
P_Node pop_back(P_Node const & head);
