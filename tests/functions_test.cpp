
#include "gtest/gtest.h"
#include "../functions.h"


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