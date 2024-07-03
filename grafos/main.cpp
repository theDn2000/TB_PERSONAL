#include <vector>
#include <memory>

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

int main (void)
{
    auto n1 = make_shared<Node<int>>(Node<int>{3});
    auto n2 = make_shared<Node<int>>(Node<int>{5});
    auto n3 = make_shared<Node<int>>(Node<int>{34});
    auto n4 = make_shared<Node<int>>(Node<int>{23});

    // Construir el grafo
    n1->neighbors.push_back(n2);
    n2->neighbors.push_back(n1); // Bidireccional
    n1->neighbors.push_back(n3);
    n3->neighbors.push_back(n4);
    return 0;
}