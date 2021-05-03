// Copyright 2021 GN
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
class MarkovChain
{
 private:
    std::vector<std::string> words;
    //typedef std::deque<std::string> prefix;
    std::map<prefix, std::vector<std::string>> statetab;
    const int NPREF = 2;
    const int MAXGEN = 1000;
 
 public:
     void MakeTable(std::string fileName);
     int MakeTableInt(std::string fileName);
     std::string CreateNewText();
     //int CreateNewTextInt();
     MarkovChain() {
         this->words;
         this->statetab;
     }

};
#endif // INCLUDE_TEXTGEN_H_