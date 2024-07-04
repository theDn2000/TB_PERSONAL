#include "grafos.h"

bool operator<(Edge const &e1, Edge const &e2)
{
    return e1.distance < e2.distance;
};

float operator-(Node_E const &n1, Node_E const &n2)
{
    return pow(n1.data.x - n2.data.x, 2) + pow(n1.data.y - n2.data.y, 2); // Sin raiz cuadrada para reducir tiempo de computacion
}