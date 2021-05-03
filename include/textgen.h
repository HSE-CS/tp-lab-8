//  Copyright 2021 kisozinov
#ifndef INCLUDE_TEXTGEN_H_
#define INCLUDE_TEXTGEN_H_

#include <string>
#include <vector>
#include <map>
#include <deque>
#include <typeinfo>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <clocale>


typedef std::deque<std::string> prefix;

const int NPREF = 2;
const int MAXGEN = 1500;

void fillStatetab(std::map<prefix, std::vector<std::string> >* statetab,
                    std::string fileName);

std::string generateText(std::map<prefix, std::vector<std::string> >* statetab,
                        prefix& start);

void printMap(std::map<prefix, std::vector<std::string> >* statetab);
#endif  //  INCLUDE_TEXTGEN_H_
