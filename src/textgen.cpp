//  Copyright 2021 alexgiving

#include <random>
#include <fstream>
#include "textgen.h"

void Analyze::ReadFile() {
  std::ifstream File;
  File.open("src/input.txt");
  if (!File.is_open()) std::cout << "ERROR. File cant ba opened";
  else {
    AnalyzeFile(&File);
    File.close();
  }
}
void Analyze::AnalyzeFile(std::ifstream* File) {
  std::string pref_str1;
  std::string pref_str2;
  std::string suff_str;
  std::map<std::deque<std::string>, std::vector<std::string>> :: iterator it;
  *File >> pref_str1;
  *File >> pref_str2;
  *File >> suff_str;
  while (!File->eof()) {
    prefix.push_back(pref_str1);
    prefix.push_back(pref_str2);
    suff.push_back(suff_str);
    it = statetab.find(prefix);
    if (it == statetab.end()) statetab.insert(std::make_pair(prefix, suff));
    else it->second.push_back(suff_str);
    prefix.clear();
    suff.clear();
    pref_str1.swap(pref_str2);
    pref_str2.swap(suff_str);
    *File >> suff_str;
  }
}
void Analyze::Generate() {
  auto it = statetab.begin();
  std::string str1 = it->first[0];
  std::string str2 = it->first[1];
  std::string str;
  size_t indx = 0;
  while (indx < MAXGEN) {
    std::random_device rd;
    std::mt19937 mersenne(rd());
    auto rand_i = static_cast<size_t>(mersenne() % it->second.size());

    text.append(str1);
    text.append(" ");
    text.append(str2);
    text.append(" ");
    text.append(it->second[rand_i]);
    text.append("\n");

    str = it->second[rand_i];
    str1.swap(str2);
    str2.swap(str);

    prefix.push_back(str1);
    prefix.push_back(str2);
    it = statetab.find(prefix);
    if (it == statetab.end()) break;
    prefix.clear();
    ++indx;
  }
}
