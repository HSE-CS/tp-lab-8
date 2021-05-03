// Copyright 2021 Lab8 TiNa
#include "textgen.h"

void add_to_tab(std::string filename_in) {
  std::ifstream filein(filename_in);
  prefix pref;
  std::string buf;
  while (!filein.eof()) {
    while (pref.size() < NPREF) {
      filein >> buf;
      if (buf != "") {
        pref.push_back(buf);
      } else {
        break;
      }
    }
    filein >> buf;
    if (buf == "") {
      return;
    }
    statetab[pref].push_back(buf);
    pref.pop_front();
    pref.push_back(buf);
    buf.clear();
  }
  filein.close();
}

void generate_text(std::string filename_out) {
  std::ofstream fileout(filename_out);
  srand(time(0));
  std::map<prefix, std::vector<std::string>>::iterator iter = statetab.begin();
  std::advance(iter, rand() % statetab.size());
  prefix pref(iter->first);
  for (auto i : iter->first) {
    fileout << i << " ";
  }
  int w_count = iter->first.size();
  std::string buf;
  int count = 0;
  while ((statetab[pref].size() != 0) && (w_count < MAXGEN)) {
    buf = statetab[pref][rand() % statetab[pref].size()];
    fileout << buf << " ";
    ++count;
    ++w_count;
    if (count > 7) {
      fileout << "\n";
      count = 0;
    }
    pref.push_back(buf);
    pref.pop_front();
  }
}
