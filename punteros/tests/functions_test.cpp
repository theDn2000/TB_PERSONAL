
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

// Test de intersection

// Compruebo que si interseccion, devuelve vector con elementos comunes
TEST(IntersectionTest, intersection_interseccion)
{
    shared_ptr<Person> p1 = make_shared<Person>("Juan", 30, "12345678A", "juan@mail.com", false);
    shared_ptr<Person> p2 = make_shared<Person>(Person{"Pedro", 30, "12345678A", "pedro@mail.com", false});
    shared_ptr<Person> p3 = make_shared<Person>(Person{"Maria", 40, "12345678A", "maria@mail,com", false});
    shared_ptr<Person> p4 = make_shared<Person>(Person{"Ana", 50, "12345678A", "ana@mail.com", false});

    vector<shared_ptr<Person>> personas = {p1, p2, p3, p4};
    vector<shared_ptr<Person>> personas2 = {p2, p3};

    vector<shared_ptr<Person>> interseccion = intersection(personas, personas2);
    EXPECT_EQ(interseccion.size(), 2);
    EXPECT_TRUE(include(interseccion, p2));
    EXPECT_TRUE(include(interseccion, p3));
}

// Compruebo que si no interseccion, devuelve vector vacio
TEST(IntersectionTest, intersection_no_interseccion)
{
    shared_ptr<Person> p1 = make_shared<Person>("Juan", 30, "12345678A", "juan@mail.com", false);
    shared_ptr<Person> p2 = make_shared<Person>(Person{"Pedro", 30, "12345678A", "pedro@mail.com", false});
    shared_ptr<Person> p3 = make_shared<Person>(Person{"Maria", 40, "12345678A", "maria@mail,com", false});
    shared_ptr<Person> p4 = make_shared<Person>(Person{"Ana", 50, "12345678A", "ana@mail.com", false});

    vector<shared_ptr<Person>> personas = {p1, p2};
    vector<shared_ptr<Person>> personas2 = {p3, p4};

    vector<shared_ptr<Person>> interseccion = intersection(personas, personas2);
    EXPEXT_EQ(interseccion.size(), 0);
    EXPECT_FALSE(include(interseccion,p1));
    EXPECT_FALSE(include(interseccion,p2));
}

// Test de unity

// Compruebo que si union, devuelve vector con elementos de ambos vectores
TEST(UnityTest, unity_union)
{
    shared_ptr<Person> p1 = make_shared<Person>("Juan", 30, "12345678A", "juan@mail.com", false);
    shared_ptr<Person> p2 = make_shared<Person>(Person{"Pedro", 30, "12345678A", "pedro@mail.com", false});
    shared_ptr<Person> p3 = make_shared<Person>(Person{"Maria", 40, "12345678A", "maria@mail,com", false});
    shared_ptr<Person> p4 = make_shared<Person>(Person{"Ana", 50, "12345678A", "ana@mail.com", false});

    vector<shared_ptr<Person>> personas = {p1, p2};
    vector<shared_ptr<Person>> personas2 = {p3};

    vector<shared_ptr<Person>> suma = unity(personas, personas2);
    EXPEXT_EQ(unity.size(), 3);
    EXPECT_TRUE(include(suma,p1));
    EXPECT_TRUE(include(suma,p3));
    EXPECT_FALSE(include(suma,p4));
}


