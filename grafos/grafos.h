#pragma once

#include <iostream>
#include <memory>
#include <functional>
#include <random>

using namespace std;

template<typename T>
struct Node
{
    T data;
    vector<shared_ptr<Node<T>>> neighbors;
};

template<typename T>
void push(shared_ptr<Node<T>> &n1, shared_ptr<Node<T>> &n2, bool bidireccional = false)
{
    if (n1 == n2)
    {
        return;
    }
    for (auto arc : n1->neighbors)
    {
        if (arc == n2)
        {
            return;
        }
    }
    if (bidireccional)
    {
        n1->neighbors.push_back(n2);
        n2->neighbors.push_back(n1);
    }
    else
    {
        n1->neighbors.push_back(n2);
    }
}

template<typename T>
void push_all(shared_ptr<Node<T>> &n1, vector<shared_ptr<Node<T>>> &nodes)
{
    for (auto n : nodes)
    {
        push<T>(n1, n);
    }
}