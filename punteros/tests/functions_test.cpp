
#include "gtest/gtest.h"
#include "../functions.h"


using namespace std;

// Test de include

// Compruebo que si incluye, devuelve true
TEST(IncludeTest, include_incluye)
{
    shared_ptr<Person> p1 = make_shared<Person>("Juan", 30, "12345678A", "juan@mail.com", false);
    shared_ptr<Person> p2 = make_shared<Person>(Person{"Pedro", 30, "12345678A", "pedro@mail.com", false});
    shared_ptr<Person> p3 = make_shared<Person>(Person{"Maria", 40, "12345678A", "maria@mail,com", false});
    vector<shared_ptr<Person>> personas = {p1, p2, p3};
    EXPECT_TRUE(include(personas, p1));
    EXPECT_TRUE(include(personas, p2));
    EXPECT_TRUE(include(personas, p3));
}

// Compruebo que si no incluye, devuelve false
TEST(IncludeTest, include_no_incluye)
{
    shared_ptr<Person> p1 = make_shared<Person>(Person{"Juan", 30, "12345678A", "juan@mail.com", false});
    shared_ptr<Person> p2 = make_shared<Person>(Person{"Pedro", 30, "12345678A", "pedro@mail.com", false});
    shared_ptr<Person> p3 = make_shared<Person>(Person{"Maria", 40, "12345678A", "maria@mail,com", false});
    shared_ptr<Person> p4 = make_shared<Person>(Person{"Ana", 50, "12345678A", "ana@mail.com", false});
    vector<shared_ptr<Person>> personas = {p1, p2, p3};
    EXPECT_FALSE(include(personas, p4));
}

// Compruebo que si incluye un vector de personas, devuelve true
TEST(IncludeTest_2, include_vector_incluye)
{
    shared_ptr<Person> p1 = make_shared<Person>("Juan", 30, "12345678A", "juan@mail.com", false);
    shared_ptr<Person> p2 = make_shared<Person>(Person{"Pedro", 30, "12345678A", "pedro@mail.com", false});
    shared_ptr<Person> p3 = make_shared<Person>(Person{"Maria", 40, "12345678A", "maria@mail,com", false});
    shared_ptr<Person> p4 = make_shared<Person>(Person{"Ana", 50, "12345678A", "ana@mail.com", false});
    
    vector<shared_ptr<Person>> personas = {p1, p2, p3, p4};
    vector<shared_ptr<Person>> personas2 = {p1, p2, p3};

    EXPECT_TRUE(include(personas, personas2));
}

// Compruebo que si no incluye un vector de personas, devuelve false
TEST(IncludeTest_2, include_vector_no_incluye)
{
    shared_ptr<Person> p1 = make_shared<Person>("Juan", 30, "12345678A", "juan@mail.com", false);
    shared_ptr<Person> p2 = make_shared<Person>(Person{"Pedro", 30, "12345678A", "pedro@mail.com", false});
    shared_ptr<Person> p3 = make_shared<Person>(Person{"Maria", 40, "12345678A", "maria@mail,com", false});
    shared_ptr<Person> p4 = make_shared<Person>(Person{"Ana", 50, "12345678A", "ana@mail.com", false});
    
    vector<shared_ptr<Person>> personas = {p1, p2, p3, p4};
    vector<shared_ptr<Person>> personas2 = {p1, p2, p3};

    EXPECT_FALSE(include(personas2, personas));
}

