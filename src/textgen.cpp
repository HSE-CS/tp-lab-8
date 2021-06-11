// Copyright 2021 Panina Polina
#include <iostream>
#include "textgen.h"


void add_to_tab(std::string fname_in) {
  std::ifstream file(fname_in);
  prefix pref;
  std::string s;
  while (!file.eof()) {
    while (pref.size() < NPREF) {
      file >> s;
      if (s == "") { break; } 
      else { pref.push_back(s); } 
    }
    file >> s; 
    if (s == "") { break; } 
    statetab[pref].push_back(s);
    pref.push_back(s);
    pref.pop_front();
    s = "";
  }
  file.close();
}


void generate(std::string fname_out) {
  std::ofstream file_out(fname_out);
  srand(time(0));
  std::map<prefix, std::vector<std::string>>::iterator iterate;
  iterate = statetab.begin();
  std::advance(iterate, rand()%statetab.size());
  prefix pref(iterate->first);
  for (auto j : iterate->first) { file_out << j << " "; } 
  int word_count = iterate->first.size();
  std::string str;
  int sum = 0;
  while ((statetab[pref].size() != 0) && (word_count < MAXGEN)) {
    int k = std::rand()%statetab[pref].size();
    str = statetab[pref][k];
    file_out << str << " ";
    sum++;
    word_count++;
    pref.push_back(str);
    pref.pop_front();
  }
}
