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

string serializeStudent(Student const &s);

ostream &operator<<(ostream &os, Student const &s);

bool operator==(Student const &st1, Student const &st2);



istream &operator>>(istream &is, Student &s);

