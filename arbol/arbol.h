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
};

struct Node
{
    Data data;
    shared_ptr<Node> left;
    shared_ptr<Node> right;
};

P_Node push(P_Node &head, int data);

P_Node push(P_Node &head, Data data);


P_Node find(P_Node &head, int data);

P_Node find(P_Node &head, Data data);
