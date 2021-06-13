// Copyright 2021 alexgiving

#ifndef INCLUDE_TEXTGEN_H_
#define INCLUDE_TEXTGEN_H_

#include <iostream>
#include <deque>
#include <vector>
#include <map>
#include <cstring>
#include <string>

const int MAXGEN = 100;

class Analyze {
 public:
  std::deque<std::string> prefix;
  std::vector<std::string> suff;
  std::string text;
  std::map<std::deque<std::string>, std::vector<std::string> > statetab;
  void ReadFile();
  void AnalyzeFile(std::ifstream* File);
  void Generate();
};

#endif  // INCLUDE_TEXTGEN_H_