//  Copyright 2021 GHA created by Klykov Anton

#include <random>
#include <fstream>
#include "textgen.h"

void Analyze::ReadFile() {
  std::ifstream File;
  File.open("src/analyze.txt");
  if (!File.is_open()) {
    std::cout << "File is not opened";
  } else {
    AnalyzeFile(&File);
    File.close();
  }
}
void Analyze::AnalyzeFile(std::ifstream* File) {
  std::string pref_str1;
  std::string pref_str2;
  std::string suff_str;
  std::map<std::deque<std::string>,
          std::vector<std::string>> :: iterator it;
  *File >> pref_str1;
  *File >> pref_str2;
  *File >> suff_str;
  while (!File->eof()) {
    prefix.push_back(pref_str1);
    prefix.push_back(pref_str2);
    suff.push_back(suff_str);
    it = statetab.find(prefix);
    if (it == statetab.end()) {
      statetab.insert(std::make_pair(prefix, suff));
    } else {
      it->second.push_back(suff_str);
    }
    prefix.clear();
    suff.clear();
    pref_str1.swap(pref_str2);
    pref_str2.swap(suff_str);
    *File >> suff_str;
  }
}
void Analyze::Generate() {
  auto it = statetab.begin();
  std::string pref_str1 = it->first[0];
  std::string pref_str2 = it->first[1];
  std::string suff_str;
  int i = 0;
  while (i < MAXGEN) {
    std::random_device rd;
    std::mt19937 mersenne(rd());
    size_t random_index = static_cast<size_t>(mersenne()
                  % it->second.size());
    suff_str = it->second[random_index];
    text += pref_str1;
    text += " ";
    text += pref_str2;
    text += " ";
    text += suff_str;
    text += "\n";
    pref_str1.swap(pref_str2);
    pref_str2.swap(suff_str);
    prefix.push_back(pref_str1);
    prefix.push_back(pref_str2);
    it = statetab.find(prefix);
    if (it == statetab.end()) {
      break;
    }
    prefix.clear();
    i++;
  }
}
