// Copyright Leonidek23 2021

#ifndef INCLUDE_TEXTGEN_H_
#define INCLUDE_TEXTGEN_H_

#include <deque>
#include <string>
#include <vector>
#include <map>

typedef std::deque<std::string> prefix;
const int NPREF = 2;
const int MAXGEN = 1500;

void AddTable(std::string path, std::map<prefix,
        std::vector<std::string>> *stateTable);

std::string Text(std::map<prefix,
        std::vector<std::string>> *stateTable);

#endif  // INCLUDE_TEXTGEN_H_
