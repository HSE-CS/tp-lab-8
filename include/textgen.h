// Copyright 2021 Panina Polina
#ifndef INCLUDE_TEXTGEN_H_
#define INCLUDE_TEXTGEN_H_
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <deque>
#include <map>
#include <typeinfo>
#include <vector>

typedef std::deque<std::string> prefix;
static std::map<prefix, std::vector<std::string>> statetab;

const int NPREF = 2;
const int MAXGEN = 1000;

void add_to_tab(std::string fname_in);
void generate(std::string fname_out);

#endif  // INCLUDE_TEXTGEN_H_
