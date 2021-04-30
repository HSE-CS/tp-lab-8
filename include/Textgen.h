//  Copyright Baklanov 2021
#ifndef INCLUDE_TEXTGEN_H_
#define INCLUDE_TEXTGEN_H_

#include <deque>
#include <vector>
#include <map>
#include <string>
#include <fstream>

typedef std::deque<std::string> prefix;
std::map<prefix, std::vector<std::string> >
makeStatetab(const int NPREF,
    const int MAXGEN,
    std::string filepath);

std::string generateText(std::map<prefix,
    std::vector<std::string> >* statetab,
    prefix* startPref);

std::string getLastWord(std::string str);

#endif  // INCLUDE_TEXTGEN_H_