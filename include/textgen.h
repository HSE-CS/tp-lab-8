// Copyright 2021 Egor Buzanov
#ifndef INCLUDE_TEXTGEN_H_
#define INCLUDE_TEXTGEN_H_

#include <deque>
#include <fstream>
#include <iostream>
#include <map>
#include <random>
#include <sstream>
#include <string>
#include <vector>

typedef std::deque<std::string> prefix;
extern std::map<prefix, std::vector<std::string>> statetab;

const size_t NPREF = 2;
const size_t MAXGEN = 1000;

void createStateTab(std::string _filename);
std::string makeText();

#endif  // INCLUDE_TEXTGEN_H_
