// Copyright 2021 Vadukk

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

class GenerationOfText
{
private:
    std::vector<std::string> words;
    typedef std::deque<std::string> prefix;
    std::map<prefix, std::vector<std::string>> statetab;
    const int NPREF = 2;
    const int MAXGEN = 1000;
public:
    void MakingTheTable(std::string text);
    std::string GenerationNewText();
    std::string ReadFromFile(std::string filename);
    void WritingToFile(std::string answer);
    GenerationOfText(std::map<prefix, std::vector<std::string> > val, std::vector<std::string> word);
    GenerationOfText();

};
#endif // !INCLUDE_TEXTGEN_H_