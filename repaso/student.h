#pragma once

#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Student
{
    string id;
    string name;
    vector<string> subjects;
};

ostream &operator<<(ostream &os, Student const &s);


/* // COMENTADO POR EL MOMENTO
istream &operator>>(istream &is, Student &s)
{
    is >> s.id;
    is >> s.name;
    string aux;
    while(is >> aux)
    {
        s.subjects.push_back(aux);
    }
    return is;
}
*/