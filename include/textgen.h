// Copyright KarMashanova 2021
#ifndef INCLUDE_TEXTGEN_H_
#define INCLUDE_TEXTGEN_H_

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <deque>
#include <fstream>
#include <ctime>
#include <map>
#include <typeinfo>

typedef std::deque<std::string> prefix;
static std::map<prefix, std::vector<std::string>> statetab;

const int NPREF = 2;
const int MAXGEN = 1000;

void AddTab(std::string f_input);
void Generating(std::string f_output);

#endif  // INCLUDE_TEXTGEN_H_