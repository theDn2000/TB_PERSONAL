
#include "gtest/gtest.h"
#include "../node.h"


using namespace std;

// Test de include

// Compruebo que si incluye, devuelve true
TEST(Push, push_head_nullptr)
{
    Student st1{"1234", "Alberto", {"Progra 1", "Progra 2", "EDA"}};
    Student st2{"1234", "Luisa", {"Progra 1", "Progra 2", "EDA"}};
    PNode head = nullptr;
    head = push(head, st1);
    EXPECT_TRUE(head !=nullptr);
    EXPECT_EQ(head->data, st1); // Comparacion estudiantes
}