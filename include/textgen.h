// Copyright 2021 Lab8 TiNa
#ifndef INCLUDE_TEXTGEN_H_
#define INCLUDE_TEXTGEN_H_

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <ctime>
#include <typeinfo>
#include <cstdlib>
#include <map>
#include <deque>

typedef std::deque<std::string> prefix;
static std::map<prefix, std::vector<std::string>> statetab;

const int NPREF = 2;
const int MAXGEN = 1000;

void add_to_tab(std::string filename_in);
void generate_text(std::string filename_out);

#endif  // INCLUDE_TEXTGEN_H_
