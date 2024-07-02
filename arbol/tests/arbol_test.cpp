#include <gtest/gtest.h>
#include "../arbol.h"

TEST(Push, push_arbol)
{
    P_Node head = nullptr;
    push(head, 10);
    push(head, 5);
    push(head, 11);
    push(head, 6);

    EXPECT_EQ(head->data, 10);
    EXPECT_EQ(head->left->data, 5);
    EXPECT_EQ(head->right->data, 11);
    EXPECT_EQ(head->left->right->data, 6);
    EXPECT_EQ(head->right->left, nullptr);
    EXPECT_EQ(head->right->right, nullptr);
}