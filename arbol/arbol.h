#pragma once

#include <iostream>
#include <memory>
#include <functional>
#include <random>

using namespace std;

struct Node;

using P_Node = shared_ptr<Node>;

struct Data
{
    int value;
    int id;
    string name;
};

struct Node
{
    shared_ptr<Data> data;
    shared_ptr<Node> left;
    shared_ptr<Node> right;
};

P_Node push(P_Node &head, int data);

P_Node push_by_value(P_Node &head, Data data);
P_Node push_by_id(P_Node &head, Data data);


P_Node find(P_Node &head, int data);

P_Node find_by_value(P_Node &head, Data data);
P_Node find_by_id(P_Node &head, Data data);
