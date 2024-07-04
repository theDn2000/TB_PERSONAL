#include <vector>
#include <memory>
#include <set>
#include "grafos.h"

using namespace std;

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

int main (void)
{
    // DIJKSTRA
    /*
    auto n1 = make_shared<Node<int>>(Node<int>{3});
    auto n2 = make_shared<Node<int>>(Node<int>{5});
    auto n3 = make_shared<Node<int>>(Node<int>{34});
    auto n4 = make_shared<Node<int>>(Node<int>{23});

    // Construir el grafo con la función push
    push_arc<int>(n1, n2, 2, true);
    push_arc<int>(n2, n4, 1, true);
    push_arc<int>(n1, n3, 1, false);
    push_arc<int>(n3, n4, 3, false);

    dijstra<int>(n1, n4);
    */

    return 0;
}