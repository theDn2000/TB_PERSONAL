#pragma once

#include <iostream>
#include <memory>

using namespace std;

struct Node;

using P_Node = shared_ptr<Node>;

struct Node
{
    int data;
    shared_ptr<Node> left;
    shared_ptr<Node> right;
};

P_Node push(P_Node &head, int data);