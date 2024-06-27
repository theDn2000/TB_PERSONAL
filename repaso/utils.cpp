#include "utils.h"

string uuid(int size)
{
  string uuid = "";
  for (int i = 0; i < size; i++)
  {
    uuid += to_string(rand() % 10);
  }
  return uuid;
}

// (name Alberto)(subjects Progra 1, Progra 2, EDA)
vector<string> splitInParenthesis(string const &s)
{
    vector<string> result;
    string temp = "";
    for (auto c : s)
    {
        if (c == '(')
        {
        temp = "";
        }
        else if (c == ')')
        {
        result.push_back(temp);
        }
        else
        {
        temp += c;
        }
    }
    return result;
}

vector<string> split(string const &s, string separator)
{
    vector<string> result;
    string temp = "";
    for (auto c : s)
    {
        if (c == separator[0])
        {
            result.push_back(temp);
            temp = "";
        }
        else
        {
            temp += c;
        }
    }
    result.push_back(temp);
    return result;
}