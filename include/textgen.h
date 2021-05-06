// Copyright 2021 Elise
#ifndef INCLUDE_TEXTGEN_H_
#define INCLUDE_TEXTGEN_H_
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <deque>
#include <typeinfo>
#include <fstream>
#include <cstdlib>
#include <ctime>


typedef std::deque<std::string> prefix;
static std::map<prefix, std::vector<std::string>> statetab;
static std::vector<std::string> buff;
const int NPREF = 2;
const int MAXGEN = 1000;

std::string read_text(std::string input_file);
void make_table(std::string text);
std::string make_new_text();
void write_text_to_file(std::string result);


#endif  // !INCLUDE_TEXTGEN_H_
