// Copyright 2021 DB

#ifndef INCLUDE_TEXTGEN_H_
#define INCLUDE_TEXTGEN_H_

#include <iostream>
#include <string>
#include <ctime>
#include <deque>
#include <fstream>
#include <map>
#include <vector>

typedef std::deque<std::string> prefix;
class MarkovChain {
 private:
  std::vector<std::string> words;
  std::map<prefix, std::vector<std::string>> statetab;
  const int NPREF = 3;
  const int MAXGEN = 1500;

 public:
  void MakeTable(std::string file);
  int MakeTableInt(std::string file);
  std::string CreateNewText();
  MarkovChain() {
    this->words;
    this->statetab;
  }
};
#endif  // INCLUDE_TEXTGEN_H_
