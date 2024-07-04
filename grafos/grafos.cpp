#include "grafos.h"

bool operator<(Edge const &e1, Edge const &e2)
{
    return e1.distance < e2.distance;
};