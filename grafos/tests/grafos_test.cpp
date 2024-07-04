#include <gtest/gtest.h>
#include "../grafos.h"

/*
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
*/

// TEST DIJKSTRA
TEST (Dijkstra, dijkstra_costes)
{
    // Ubicate nodes
    auto c1 = Coordinates{0, 0};
    auto c2 = Coordinates{2, 0};
    auto c3 = Coordinates{1, 1};
    auto c4 = Coordinates{4, 2};
    auto c5 = Coordinates{2, 3};

    // Create nodes
    auto n1 = make_shared<Node_E>(Node_E{c1});
    auto n2 = make_shared<Node_E>(Node_E{c2});
    auto n3 = make_shared<Node_E>(Node_E{c3});
    auto n4 = make_shared<Node_E>(Node_E{c4});
    auto n5 = make_shared<Node_E>(Node_E{c5});

    // Create graph
    push(n1, n2, false);
    push(n2, n3, true);
    push(n2, n4, true);
    push(n3, n5, false);
    push(n4, n5, false);

    // Dijkstra
    dijkstra(n1, {n1, n2, n3, n4, n5});

    // Check costs
    EXPECT_EQ(n1->cost, 0);
    EXPECT_EQ(n2->cost, 4);

    // Check path
    EXPECT_EQ(n5->prev->data.y, 1);
    EXPECT_EQ(n5->prev->prev->data.y, 0);
}