#pragma once

#include <set>
#include <iostream>
#include <memory>
#include <functional>
#include <random>

using namespace std;
// DIJKSTRA
/*
template<typename G>
struct Arc;

template<typename T>
struct Node
{
    T data;
    int cost = INT_MAX;
    vector<Arc<T>> neighbors;
    Node<T> prev = nullptr;
};

template<typename G>
struct Arc
{
    int weight;
    shared_ptr<Node<G>> node;
};
*/


// ESTRELLA
struct Coordinates
{
    int x;
    int y;
};

struct Node_E;

struct Edge
{
    shared_ptr<Node_E> node;
    float distance;
};

struct Node_E
{
    Coordinates data;
    set<Edge> neighbors;
    float cost = INT_MAX;
    shared_ptr<Node_E> prev = nullptr;
};

bool operator<(Edge const &e1, Edge const &e2)
{
    return e1.distance < e2.distance;
}
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
// DIJKSTRA
/*
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
void dijstra(shared_ptr<Node<T>> &start, vector<shared_ptr<Node<T>>> &nodes)
{
    set<shared_ptr<Node<T>>> visited;
    set<shared_ptr<Node<T>>> unvisited = nodes;
    start->cost = 0;

    while(unvisited.size() > 0)
    {
        shared_ptr<Node<T>> current; = *unvisited.begin();
        for (auto elem : unvisited)
        {
            if (elem->cost < current->cost)
            {
                current = elem;
            }
        }

        for (auto neighbor : current->neighbors)
        {
            auto new_cost = current->cost + neighbor.weight;
            if (new_cost < neighbor.node->cost)
            {
                neighbor.node->cost = new_cost;
                neighbor.node->prev = current;
            }
        }

        unvisited.erase(find(unvisited.begin(), unvisited.end(), current));
    }
}
*/



// ESTRELLA
float operator-(Node_E const &n1, Node_E const &n2)
{
    return pow(n1.data.x - n2.data.x, 2) + pow(n1.data.y - n2.data.y, 2); // Sin raiz cuadrada para reducir tiempo de computacion
}


void push(shared_ptr<Node_E> &n1, shared_ptr<Node_E> &n2, bool bidireccional = false)
{
    auto edge = Edge{n2, *n2 - *n1}; // Camino entre n1 y n2, con su distancia
    n1->neighbors.insert(edge);

    if (bidireccional)
    {
        auto edge = Edge{n1, *n1 - *n2};
        n2->neighbors.insert(edge);
    }
}

void dijkstra(shared_ptr<Node_E> &start, vector<shared_ptr<Node_E>> &nodes)
{
    start->cost = 0;
    auto NOT_VISITED = nodes;

    while (NOT_VISITED.size() > 0)
    {
        auto current = NOT_VISITED.at(0);
        for (auto node : NOT_VISITED)
        {
            if (node->cost < current->cost)
            {
                current = node;
                
            }
        }
        // Remove current from NOT_VISITED
        NOT_VISITED.erase(find(NOT_VISITED.begin(), NOT_VISITED.end(), current));

        for (auto edge : current->neighbors)
        {
            if (edge.node->cost > current->cost + edge.distance)
            {
                edge.node->cost = current->cost + edge.distance;
                edge.node->prev = current;
            }
        }
    }
}