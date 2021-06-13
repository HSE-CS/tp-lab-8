#ifndef TP_LAB_8_TEXTGEN_H
#define TP_LAB_8_TEXTGEN_H

#include <fstream>
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <ctime>
#include <map>


typedef std::deque<std::string> prefix;
std::map<prefix, std::vector<std::string>> statetab;

std::vector<std::string> b;

const int NPREF = 2;
const int MAXGEN = 1000;

void createTable(std::string);
std::string createText();



#endif //TP_LAB_8_TEXTGEN_H
