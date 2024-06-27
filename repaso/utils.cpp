#include "utils.h"




string uuid() // Genera un uuid
{
    string uuid = "";
    for (int i = 0; i < 8; i++)
    {
        uuid += to_string(rand() % 10);
    }
    return uuid;
};
