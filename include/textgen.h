// Copyright 2021 Egor Buzanov
#ifndef INCLUDE_TEXTGEN_H_
#define INCLUDE_TEXTGEN_H_

#include <deque>
#include <fstream>
#include <map>
#include <string>
#include <vector>

typedef std::deque<std::string> prefix;
std::map<prefix, std::vector<std::string>> statetab;

const int NPREF = 2;
const int MAXGEN = 1000;

#endif  // INCLUDE_TEXTGEN_H_
