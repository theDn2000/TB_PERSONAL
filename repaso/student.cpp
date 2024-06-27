#include "student.h"




ostream &operator<<(ostream &os, Student const &s)
{
    os << "ID:" << s.id << endl;
    os << "Name:" << s.name << endl;
    os << "Subjects: \n_____________\n";
    for (auto elem : s.subjects)
    {
        os << "\t" << elem << endl;
    }
    return os;
}

bool operator==(Student const &st1, Student const &st2)
{
    return st1.id == st2.id;
}

// (name Alberto)(subjects Progra 1, Progra 2, EDA)
istream &operator>>(istream &is, Student &s)
{
    string line;
    getline(is, line);
    // (name Alberto)(subjects Progra 1, Progra 2, EDA)
}