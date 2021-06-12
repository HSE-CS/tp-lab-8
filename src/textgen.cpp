// Copyright 2021 Egor Buzanov

#include "../include/textgen.h"

std::map<prefix, std::vector<std::string>> statetab;

void createStateTab(std::string _filename) {
  std::ifstream inpit_file(_filename);
  std::string str;
  prefix words;

  while (std::getline(inpit_file, str)) {
    if (str.empty()) {
      break;
    }
    std::stringstream strs(str);
    while (strs >> str) {
      words.push_back(str + " ");
    }
    words.back() += "\n";
  }
  inpit_file.close();

  while (words.size() >= NPREF) {
    prefix pref;
    for (size_t i = 0; i < NPREF; i++) {
      pref.push_back(words[i]);
    }
    statetab[pref].push_back(words[NPREF - 1]);
    words.pop_front();
  }
  for (const auto& item : statetab) {
    std::cout << item.first[0] << " " << item.first[1] << std::endl;
  }
}

std::string makeText() {
  std::string result;
  std::random_device rd;
  std::mt19937 mersenne(rd());

  for (const auto& item : statetab) {
    for (const auto& word : item.first) {
      result += word;
    }
    result += item.second[mersenne() % item.second.size()];
    if (result.size() > MAXGEN) {
      result.erase(MAXGEN);
      break;
    }
  }
  return result;
}
