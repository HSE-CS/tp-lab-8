//  Copyright 2021 idpas
#include "textgen.h"

void text_generating(std::string &outputFile) {
  std::ofstream out(outputFile);
  std::srand(std::time(0));
  std::map<prefix, std::vector<std::string>>::iterator it;
  it = statetab.begin();
  size_t a = std::rand() % statetab.size();
  std::advance(it, a);
  std::string out_str = "";
  std::string tmp_str = "";
  prefix pref(it->first);
  for (auto i : it->first) {
    out_str += i + " ";
  }
  int num = it->first.size();
  while (statetab[pref].size() != 0 && num < MAXGEN) {
    int j = std::rand() % statetab[pref].size();
    tmp_str = statetab[pref][j];
    out_str += tmp_str + " ";
    pref.push_back(tmp_str);
    pref.pop_front();
    num++;
  }
  out << out_str;
}

void add_to_state_tab(prefix &pr, std::string &s, std::string file_name) {
  std::ofstream in(file_name);
  prefix pref;
  std::string buf;
  while (!in.eof()) {
    while (pref.size() < NPREF) {
      in >> buf;
      pref.push_back(buf);
      buf.clear();
    }
    in >> buf;
    statetab[pref].push_back(buf);
    pref.pop_front();
    pref.push_back(buf);
    buf.clear();
  }
  in.close();
}
