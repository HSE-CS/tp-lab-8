// Copyright 2021 Bogomazov Mikhail
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

class GenerationOfText {
 private:
    const int NPREF = 2;
    const int MAXGEN = 1000;
    std::vector<std::string> words;
    typedef std::deque<std::string> prefix;
    std::map<prefix, std::vector<std::string>> stateTab;

 public:
    GenerationOfText(
        std::map<prefix, std::vector<std::string>> val,
        std::vector<std::string> word);
    GenerationOfText();
    void genTable(std::string text);
    std::string genText();
    std::string readFromFile(std::string filename);
    void writeToFile(std::string answer);
};
#endif  //  INCLUDE_TEXTGEN_H_
