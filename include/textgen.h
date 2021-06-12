// Copyright 2021 DBarinov
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

class TextGenerator
{
private:
    std::vector<std::string> words;
    typedef std::deque<std::string> prefix;
    std::map<prefix, std::vector<std::string>> postab;
    const int NPREF = 2;
    const int MAXGEN = 3000;
public:
    void CreateTable(std::string text);
    std::string newText();
    std::string fileInput(std::string filename);
    void fileOutput(std::string output);
    TextGenerator(std::map<prefix, std::vector<std::string> > val, std::vector<std::string> word);
    TextGenerator();

};
#endif // !INCLUDE_TEXTGEN_H_