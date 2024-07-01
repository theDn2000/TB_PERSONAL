#pragma once

#include <string>
#include <vector>
#include <chrono>

using namespace std;

string uuid(int size);

vector<string> splitInParenthesis(string const &s);
vector<string> split(string const &s, char delim);
string &trim(string &s);