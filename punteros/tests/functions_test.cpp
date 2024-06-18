
#include "gtest/gtest.h"
#include "../functions.h"


using namespace std;

// Test de include

// Compruebo que si incluye, devuelve true
TEST(IncludeTest, include_incluye)
{
    shared_ptr<Person> p1 = make_shared<Person>{"Juan", 20};
    shared_ptr<Person> p2 = make_shared<Person>{"Pedro", 30};
    shared_ptr<Person> p3 = make_shared<Person>{"Maria", 40};
    vector<shared_ptr<Person>> personas = {p1, p2, p3};
    EXPECT_TRUE(include(personas, p1));
    EXPECT_TRUE(include(personas, p2));
    EXPECT_TRUE(include(personas, p3));
}

// Compruebo que si no incluye, devuelve false
TEST(IncludeTest, include_no_incluye)
{
    shared_ptr<Person> p1 = make_shared<Person>{"Juan", 20};
    shared_ptr<Person> p2 = make_shared<Person>{"Pedro", 30};
    shared_ptr<Person> p3 = make_shared<Person>{"Maria", 40};
    shared_ptr<Person> p4 = make_shared<Person>{"Ana", 50};
    vector<shared_ptr<Person>> personas = {p1, p2, p3};
    EXPECT_FALSE(include(personas, p4));
}


