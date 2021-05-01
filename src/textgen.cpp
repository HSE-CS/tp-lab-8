// Copyright 2021 Kuznetsov Mikhail

#include "textgen.h"
#include <fstream>

std::map<prefix, std::vector<std::string>> statetab;  // префикс-суффиксы
std::vector<prefix> prefixes;
std::set<char> punctuationMarks = {'.', ',', ':', ';', '-',
'"', '?', '!', '(', ')', '/', '\\', '#', '*', '<', '>'};

bool createStateTab(std::string _fileIn) {
  std::ifstream fin(_fileIn);
  if(!fin.is_open()) {
    return false;
  }
  prefix pref;
  for (int i = 0; !fin.eof(); i = std::min(i + 1, NPREF)) {
    std::string word;
    fin >> word;
    if (!erasePunctuationMarksAndCapitals(word))
      continue;
    if (i >= NPREF) {
      statetab[pref].push_back(word);
      prefixes.push_back(pref);
      pref.pop_front();
    }
    pref.push_back(word);
  }
  fin.close();
  return true;
}

bool erasePunctuationMarksAndCapitals(std::string& _word) {
  for (int i = 0; i < int(_word.size()); i++) {
    if (_word[i] >= 'A' && _word[i] <= 'Z') {
      _word[i] += 'a' - 'A';
    }
    else if (punctuationMarks.count(_word[i])) {
      _word.erase(i, 1);
      i--;
    }
  }
  if (_word.size())
    return true;
  return false;
}

bool generateText(std::string _fileOut) {
  std::ofstream fout(_fileOut);
  if (!fout.is_open()) {
    return false;
  }
  prefix pref = prefixes[std::rand() % prefixes.size()];
  for(auto word : pref) {
    fout << word << ' ';
  }
  for (int i = 0; i < MAXGEN; i++) {
    auto start = statetab.find(pref);
    if (start == statetab.end())
      continue;
    std::string suff = start->second[std::rand() % start->second.size()];
    fout << suff << ' ';
    pref.pop_front();
    pref.push_back(suff);
  }
  return true;
}
