// Copyright 2021 ch2oh-ch2oh

#include "textgen.h"

#include <sstream>

void add(const prefix& p, const std::string& word,
         std::map<prefix, std::vector<std::string>>* statetab) {
  for (auto& it : *statetab) {
    if (it.first == p) {
      it.second.push_back(word);
      return;
    }
  }
  (*statetab)[p].push_back(word);
}

prefix map_fill(const std::string& input,
                std::map<prefix, std::vector<std::string>>* statetab) {
  std::stringstream stream(input);
  std::string word;
  prefix first_pref;
  first_pref.push_back("");
  for (int i = 1; i < NPREF; ++i) {
    stream >> word;
    first_pref.push_back(word);
  }
  prefix p = first_pref;

  while (stream >> word) {
    add(p, word, statetab);
    p.push_back(word);
    p.pop_front();
  }
  add(p, "", statetab);
  // print_state(statetab);
  return first_pref;
}

std::string read_file(const std::string& input) {
  std::ifstream file(input);
  std::string s;
  std::string raw;
  while (!file.eof()) {
    std::getline(file, s);
    raw += " " + s;
  }
  raw.erase(0, 1);
  return raw;
}

void print_state(std::map<prefix, std::vector<std::string>>* statetab) {
  for (auto& it : (*statetab)) {
    std::cout << (it.first)[0] << " " << (it.first)[1] << "\t";
    for (auto& i : it.second) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }
}

std::string get(const std::map<prefix, std::vector<std::string>>& statetab,
                const prefix& p) {
  for (auto& it : statetab) {
    if (p == it.first) {
      return it.second[rand_r(&seed) % it.second.size()];
    }
  }
  return "";
}

std::string generate(const std::map<prefix, std::vector<std::string>>& statetab,
                     const prefix& first_pref) {
  std::string text;
  prefix p = first_pref;
  int counter = 0;
  while (!p[0].empty() && counter < MAXGEN || counter == 0) {
    text += p[0] + " ";
    p.push_back(get(statetab, p));
    p.pop_front();
    counter++;
  }
  text.erase(text.length() - 1);
  text.erase(0, 1);
  return text;
}
