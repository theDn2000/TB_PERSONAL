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