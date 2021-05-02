// Copyright 2021 Vlad

#ifndef INCLUDE_TEXTGEN_H_
#define INCLUDE_TEXTGEN_H_
#include <deque>
#include <string>
#include <vector>
#include <map>

typedef std::deque<std::string> prefix;
const int NPREF = 2;
const int MAXGEN = 1500;

void createStateTable(std::string fileName, std::map<prefix, 
    std::vector<std::string>>* stateTable);

std::string generateText(std::map<prefix,
    std::vector<std::string>>*stateTable);
#endif  // INCLUDE_TEXTGEN_H_
