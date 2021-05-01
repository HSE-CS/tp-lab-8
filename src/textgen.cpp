#include "../include/textgen.h"
#include <iostream>
#include <algorithm>
#include<ctime>

void normalize(std::string& buff) {
  for (size_t i = 0; i < buff.size(); ++i) {
    if (buff.at(i) >= 'À' && buff.at(i) <= 'ß') {
      buff[i] = char(buff[i] - 'À' + 'à');
    } else {
      if (buff.at(i) >= 'A' && buff.at(i) <= 'Z') {
        buff.at(i) = char(buff.at(i) - 'A' + 'a');
      }
    }
  }
}

void addToStatetab(prefix &pr, std::string &s) {
  normalize(s);
  if (s == "") return;
  statetab[pr].push_back(s);
  pr.pop_front();
  pr.push_back(s);
}

void printStatetab(const std::string& outputFile) {
  std::ofstream out(outputFile);
  for (std::map<prefix, std::vector<std::string>>::iterator it =
           statetab.begin();
       it != statetab.end(); ++it) {
    for (auto i : it->first) {
      out << i << " ";
    }
    out << "-> " << it->second.size() << " -> ";
    for (auto i : it->second) {
      out << i << " ";
    }
    out << "\n";
  }
}

void education(std::string& inputFile) {
  std::string buff;
  std::ifstream input(inputFile);
  prefix pref;
  while (pref.size() < NPREF) {
    input >> buff;
    normalize(buff);
    if (buff !="") {
      pref.push_back(buff);
    } else {
      break;
    }
  }
  while (!input.eof()) {
    input >> buff;
    addToStatetab(pref, buff);
  }
  printStatetab(std::string("test.txt"));
}

void generate(std::string& outputFile) {
  std::ofstream out(outputFile);
  std::srand(std::time(0));
  std::map<prefix, std::vector<std::string>>::iterator it = statetab.begin();
  std::advance(it, std::rand() % statetab.size());
  prefix pref(it->first);
  for (auto i : it->first) {
    out << i << " ";
  }
  int wordCount = it->first.size();
  std::string buff;
  int count = 0;
  while (statetab[pref].size() != 0 && wordCount < MAXGEN) {
    buff = statetab[pref][std::rand() % statetab[pref].size()];
    out << buff << " ";
    ++count;
    if (buff[buff.size() - 1] == '.' || buff[buff.size() - 1] == '!' ||
        buff[buff.size() - 1] == ':' || buff[buff.size() - 1] == ';' ||
        buff[buff.size() - 1] == '»') {
      out << "\n";
      count = 0;
    }
    ++wordCount;
    if (count > 5) {
      out << "\n";
      count = 0;
    }
    pref.push_back(buff);
    pref.pop_front();
  }
}
