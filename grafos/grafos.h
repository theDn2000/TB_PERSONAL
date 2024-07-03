#pragma once

#include <set>
#include <iostream>
#include <memory>
#include <functional>
#include <random>

using namespace std;
template<typename G>
struct Arc;

template<typename T>
struct Node
{
    T data;
    vector<Arc<T>> neighbors;
};

template<typename G>
struct Arc
{
    int weight;
    shared_ptr<Node<G>> node;
};
/*
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
*/

template<typename T>
void push_arc(shared_ptr<Node<T>> &n1, shared_ptr<Node<T>> &n2, int const &cost, bool bidireccional = false)
{
    if (n1 == n2)
    {
        return;
    }
    for (auto arc : n1->neighbors)
    {
        if (arc.node == n2)
        {
            return;
        }
    }
    if (bidireccional)
    {
        n1->neighbors.push_back(Arc<T>{cost, n2});
        n2->neighbors.push_back(Arc<T>{cost, n1});
    }
    else
    {
        n1->neighbors.push_back(Arc<T>{cost, n2});
    }
}

template<typename T>
void push_all(shared_ptr<Node<T>> &n1, vector<shared_ptr<Node<T>>> const &nodes)
{
    for (auto n : nodes)
    {
        push<T>(n1, n);
    }
}

template<typename T>
vector<Arc<T>> dijstra(shared_ptr<Node<T>> &start, shared_ptr<Node<T>> &end)
{
    vector<Arc<T>> result;
    set<shared_ptr<Node<T>>> visited;
    set<shared_ptr<Node<T>>> unvisited;
    unvisited.insert(start);
    for (auto element : unvisited)
    {
        for (auto elem : start->neighbors)
        {
            unvisited.insert(elem.node);
        }
    }

    for (auto element : unvisited)
    {
        cout << element->data << endl;
    }
    result = {Arc<T>{1, start}};
    return result;
}