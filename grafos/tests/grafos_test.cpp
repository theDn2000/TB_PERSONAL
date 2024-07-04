#include <gtest/gtest.h>
#include "../grafos.h"

TEST (Grafos, push_grafo)
{
    auto n1 = make_shared<Node<int>>(Node<int>{3});
    auto n2 = make_shared<Node<int>>(Node<int>{5});
    auto n3 = make_shared<Node<int>>(Node<int>{34});
    auto n4 = make_shared<Node<int>>(Node<int>{23});

    // Construir el grafo
    push<int>(n1, n2, true);
    push<int>(n1, n3, false);
    push<int>(n3, n4, false);
    push<int>(n1, n2, true);

    EXPECT_EQ(n1->neighbors.size(), 2);
    EXPECT_EQ(n2->neighbors.size(), 1);
    EXPECT_EQ(n3->neighbors.size(), 1);
    EXPECT_EQ(n4->neighbors.size(), 0);
    EXPECT_EQ(n1->neighbors[0]->data, 5);
}

TEST (Grafos, push_all_grafo)
{
    auto n1 = make_shared<Node<int>>(Node<int>{3});
    auto n2 = make_shared<Node<int>>(Node<int>{5});
    auto n3 = make_shared<Node<int>>(Node<int>{34});
    auto n4 = make_shared<Node<int>>(Node<int>{23});

    // Construir el grafo
    push_all<int>(n1, {n1, n2, n3});
    push_all<int>(n1, {n1, n2, n4});

    EXPECT_EQ(n1->neighbors.size(), 3);
    EXPECT_EQ(n1->neighbors[1]->data, 34);
}