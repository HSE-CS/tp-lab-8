// Copyright 2021 GHA Test Team
#ifndef INCLUDE_TESTGEN_H_
#define INCLUDE_TESTGEN_H_

#include <deque>
#include <string>
#include <vector>
#include <map>
#include <fstream>

typedef std::deque<std::string> prefix;
static std::map<prefix, std::vector<std::string>> statetab;

const int NPREF = 2;
const int MAXGEN = 1000;

void education(std::string& inputFile);
void generate(std::string& outputFile);
void addToStatetab(prefix &pr, std::string &s);
void printStatetab(const std::string& outputFile);

#endif  // !INCLUDE_TESTGEN_H_
