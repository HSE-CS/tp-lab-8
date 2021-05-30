// Copyright 2021 by Liza
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

const int NPREF = 2;
const int MAXGEN = 1000;

class TextGeneration {
 private:
std::vector<std::string> words;
typedef std::deque<std::string> prefix;
std::map<prefix, std::vector<std::string>> statetab;
 public:
void MakingTheTable(std::string text);
std::string NewText();
std::string ReadFromFile(std::string filename);
TextGeneration(std::map<prefix, std::vector<std::string> > val, std::vector<std::string> word);
TextGeneration();};
#endif // INCLUDE_TEXTGEN_H_
