//  Copyright 2021 Schenikova

#include "textgen.h"

void addToStadeTab(std::string fileName) {
  std::ifstream input(fileName);
  prefix pref;
  std::string str;
  while (!input.eof()) {
    while (pref.size() < NPREF) {
      input >> str;
      if (str !="") {
        pref.push_back(str);
      } else {
        break;
      }
    }
    input >> str;
    if (str == "") {
      return;
    }
    statetab[pref].push_back(str);
    pref.pop_front();
    pref.push_back(str);
    str.clear();
  }
  input.close();
}

void generate(std::string outputFile) {
  std::ofstream out(outputFile);
  std::srand(std::time(0));
  std::map<prefix, std::vector<std::string>>::iterator it = statetab.begin();
  std::advance(it, std::rand() % statetab.size());
  prefix pref(it->first);
  for (auto i : it->first) {
    out << i << " ";
  }
  int wordCount = it->first.size();
  std::string str;
  int count = 0;
  while (statetab[pref].size() != 0 && wordCount < MAXGEN) {
    str = statetab[pref][std::rand() % statetab[pref].size()];
    out << str << " ";
    ++count;
    ++wordCount;
    if (count > 5) {
      out << "\n";
      count = 0;
    }
    pref.push_back(str);
    pref.pop_front();
  }
}



