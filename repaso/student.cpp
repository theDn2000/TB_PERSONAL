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