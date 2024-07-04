#include "grafos.h"

bool operator<(Edge const &e1, Edge const &e2)
{
    return e1.distance < e2.distance;
};

float operator-(Node_E const &n1, Node_E const &n2)
{
    return pow(n1.data.x - n2.data.x, 2) + pow(n1.data.y - n2.data.y, 2); // Sin raiz cuadrada para reducir tiempo de computacion
}

void push(shared_ptr<Node_E> &n1, shared_ptr<Node_E> &n2, bool bidireccional)
{
    auto edge = Edge{n2, *n2 - *n1}; // Camino entre n1 y n2, con su distancia
    n1->neighbors.insert(edge);

    if (bidireccional)
    {
        auto edge = Edge{n1, *n1 - *n2};
        n2->neighbors.insert(edge);
    }
}

void dijkstra(shared_ptr<Node_E> &start, const vector<shared_ptr<Node_E>> &nodes)
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

bool a_star(shared_ptr<Node_E> &start, shared_ptr<Node_E> &end, const vector<shared_ptr<Node_E>> &nodes)
{
    start->cost = 0;
    auto NOT_VISITED = nodes;

    // Estimate the cost from start to end for each node
    for (auto node : nodes)
    {
        node->estimation = *node - *end;
    }
    auto current = start;
    while (current != end && NOT_VISITED.size() > 0)
    {
        for (auto node : NOT_VISITED)
        {
            if (node->cost + node->estimation < current->cost + current->estimation)
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
    return current == end; // Se si ha llegado al final
}