
#include "gtest/gtest.h"
#include "../functions.h"

/*
// SUMA
TEST(SumaTest, suma_correctamente)
{
    EXPECT_EQ(suma(3, 4), 7);
}

// Compruebo el caso correcto
TEST(SumaPTest, sumaP_correctamente)
{
    EXPECT_EQ(sumaP(3, 4), 7);
}

// Compruebo que si suma negativo, lanza excepcion
TEST(SumaPTest, sumaP_lanzaerror)
{
    EXPECT_ANY_THROW(sumaP(3, -4));
}

// Compruebo que si no suma negativo, no lanza excepcion
TEST(SumaPTest, sumaP_no_lanzaerror)
{
    EXPECT_NO_THROW(sumaP(3, 4));
}
*/


// FUNCION SEPARATE_STRING
// Compruebo que separa correctamente
TEST(SeparateStringTest, separate_string_correctamente)
{
    std::string s = "(hola)(que)(tal)";
    std::vector<std::string> v = separate_string(s);
    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v[0], "hola");
    EXPECT_EQ(v[1], "que");
    EXPECT_EQ(v[2], "tal");
}

// Compruebo que separa por niveles
TEST(SeparateStringTest, separate_string_niveles)
{
    std::string s = "((hola)(que))(tal)";
    std::vector<std::string> v = separate_string(s);
    EXPECT_EQ(v.size(), 2);
    EXPECT_EQ(v[0], "(hola)(que)");
    EXPECT_EQ(v[1], "tal");
}

//Compruebo que da error si no inicia con parentesis
TEST(SeparateStringTest, separate_string_error)
{
    std::string s = "hola)(que)(tal)";
    EXPECT_ANY_THROW(separate_string(s));
} 

// Compruebo que da error si no se abren los mismos parentesis que se cierran
TEST(SeparateStringTest, separate_string_error2)
{
    std::string s = "(hola)(que)(tal";
    EXPECT_ANY_THROW(separate_string(s));
}

// Compruebo que da error si no se acaba con parentesis
TEST(SeparateStringTest, separate_string_error3)
{
    std::string s = "(hola)(que)(tal";
    EXPECT_ANY_THROW(separate_string(s));
}

// Compruebo que si no hay algo entre parentesis devuelve error
TEST(SeparateStringTest, separate_string_error4)
{
    std::string s = "()";
    EXPECT_ANY_THROW(separate_string(s));
}

// Compruebo que si hay texto que no esta entre parentesis, devuelve error
TEST(SeparateStringTest, separate_string_error5)
{
    std::string s = "(hola)que(tal)";
    EXPECT_ANY_THROW(separate_string(s));
}
