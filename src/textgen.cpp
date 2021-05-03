//  Copyright 2021 NikiDemoShow
#include<algorithm>
#include "textgen.h"

void fulfilStatetab(std::map<prefix, std::vector<std::string>>& statetab,
  std::string dir) {
  std::ifstream file(dir);
  prefix Pr;
  while (file) {
    if (Pr.empty()) {
      for (size_t i = 0; i < NPREF; ++i) {
        std::string pref;
        file >> pref;
        Pr.push_back(pref);
      }
      std::string postf;
      file >> postf;
      statetab[Pr].push_back(postf);
      Pr.pop_front();
      Pr.push_back(postf);
    }
    else {
      std::string postf;
      file >> postf;
      if (std::find(statetab[Pr].begin(), statetab[Pr].end(), postf) == statetab[Pr].end()) {
        statetab[Pr].push_back(postf);
      }
      Pr.pop_front();
      Pr.push_back(postf);
    }
  }
  file.close();
}

void generateText(std::map<prefix, std::vector<std::string>>& statetab,
  prefix& start, std::string dir) {
  std::string outT;
  unsigned cnt = NPREF;
  while ((cnt <= MAXGEN) && (!(statetab[start].empty()))) {
    if (outT.empty()) {
      for (auto pref = start.begin(); pref != start.end(); ++pref) {
        if (pref != start.end() - 1) {
          outT += *pref + " ";
        }
        else {
          outT += *pref;
        }
      }
    }
    unsigned postf = std::rand() % statetab[start].size();
    outT += " " + statetab[start][postf];
    start.push_back(statetab[start][postf]);
    start.pop_front();
    if (!(cnt % 5)) {
      outT += "\n";
    }
    cnt++;
  }
  std::ofstream file("outT.txt");
  file << outT;
  file.close();
}
