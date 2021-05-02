// Copyright Kasyanov 2021
#ifndef _INCLUDE_TEXTGEN_H
#define _INCLUDE_TEXTGEN_H

#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <deque>

typedef std::deque<std::string> prefix;
const int MAXGEN = 50;

std::vector<std::string> createWordVector(std::string);
std::map<prefix, std::vector<std::string>> createTable(std::vector<std::string>);
std::string generateText(std::map<prefix, std::vector<std::string>>);

#endif  // _INCLUDE_TEXTGEN_H
