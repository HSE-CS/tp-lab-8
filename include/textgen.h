//  Copyright 2021 Nikita Naumov
#ifndef INCLUDE_TEXTGEN_H_
#define INCLUDE_TEXTGEN_H_

#include <string>
#include <deque>
#include <vector>
#include <map>
#include <typeinfo>
#include <iostream>
#include <fstream>

typedef std::deque<std::string> prefix;  //  prefix deque

const int NPREF = 2;  //  amount of words in prefix
const int MAXGEN = 1000;  //  generated text volume

void fulfilStatetab(std::string fileName, 
                    std::map<prefix, std::vector<std::string>>* statetab);

std::string generateText(std::map<prefix, std::vector<std::string>>* statetab,
                        prefix start);
#endif  //  INCLUDE_TEXTGEN_H_
