#include "student.h"
#include "utils.h"
#include <fstream>

using namespace std;

string serializeStudent(Student const &s)
{
    string result = "(name " + s.name + ")(subjects ";
    for (auto elem : s.subjects)
    {
        result += elem + ", ";
    }
    // Remove the last comma
    result.pop_back();
    // Add the closing parenthesis
    result += ")";
    return result;
}

ostream &operator<<(ostream &os, Student const &s)
{
    if (typeid(os) == typeid(ofstream))
    {
        os << serializeStudent(s);
        return os;
    }
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
istream &operator>>(istream &is, Student &s) // Creo un objeto de tipo Student a partir de un string
{
    string line;
    getline(is, line);
    // (name Alberto)(subjects Progra 1, Progra 2, EDA)

    auto parts = splitInParenthesis(line);

    for (auto part : parts)
    {
        auto tokens = split(part, " ");
        if (tokens.at(0) == "name")
        {
            string name = "";
            
        }
        else if (tokens.at(0) == "subjects")
        {
            auto subjects = split(tokens.at(1), ",");
            for (auto subject : subjects)
            {
                s.subjects.push_back(trim(subject));
            }
        }
    }

















    return is;
}