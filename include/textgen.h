//  Copyright 2021 Urtyukov Ilya
#ifndef INCLUDE_TEXTGEN_H_
#define INCLUDE_TEXTGEN_H_

#include <string>
#include <deque>
#include <vector>
#include <map>
#include <typeinfo>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>


typedef std::deque<std::string> prefix;
static std::map<prefix, std::vector<std::string>> statetab;

const int NPREF = 2;
const int MAXGEN = 1000;


void addToStadeTab(std::string fileName);
void generate(std::string outputFile);
#endif  //  INCLUDE_TEXTGEN_H_ 
