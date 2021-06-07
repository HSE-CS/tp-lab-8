// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include"textgen.h"
TEST(textgen, test1) {
  std::map<prefix, std::vector<std::string>> statetab;
  prefix Pr;
  Pr.push_back("To");
  Pr.push_back("be");
  statetab[Pr].push_back("or");
  generateText(statetab, Pr, "outT.txt");
  std::ifstream file("outT.txt");
  std::string rez;
  while (file) {
    std::string w;
    file >> w;
    rez += w + ' ';
  }
  EXPECT_EQ(rez, "To be or  ");
}
TEST(textgen, test2) {
  srand(time(NULL));
  std::map<prefix, std::vector<std::string>> statetab;
  fulfilStatetab(statetab, "text10.txt");
  EXPECT_EQ(statetab.size(), 10);
}
TEST(textgen, test3) {
  srand(time(NULL));
  std::map<prefix, std::vector<std::string>> statetab;
  fulfilStatetab(statetab, "text.txt");
  prefix start;
  start.push_back("To");
  start.push_back("be,");
  generateText(statetab, start, "outT.txt");
  std::ifstream file("outT.txt");
  std::vector<std::string> rez;
  while (file) {
    std::string w;
    file >> w;
    rez.push_back(w);
  }
  EXPECT_EQ(rez.size() < 1500 + 2, true);
}
TEST(textgen, test4) {
  std::map<prefix, std::vector<std::string>> statetab;
  prefix Pr;
  Pr.push_back("To");
  Pr.push_back("be");
  statetab[Pr].push_back("or");
  unsigned postfI = std::rand() % statetab[Pr].size();
  std::string postf = statetab[Pr][postfI];
  EXPECT_EQ(postf, "or");
}
