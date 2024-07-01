#pragma once

#include <string>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

string uuid(int size);

vector<string> splitInParenthesis(string const &s);
vector<string> split(string const &s, char delim);
string &trim(string &s);