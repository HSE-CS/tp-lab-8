// Copyright 2021 idpas
#include <gtest/gtest.h>
#include "../include/textgen.h"

TEST(textgen, test1) {
  std::map<prefix, std::vector<std::string>> statetab;
  prefix pref;
  pref.push_back("one");
  EXPECT_EQ(1, pr.size());
}

TEST(textgen, test2) {
  std::map<prefix, std::vector<std::string>> statetab;
  prefix pref;
  pref.push_back("one");
  pref.push_back("two");
  pref.pop_front();
  EXPECT_EQ("two", pr.at(0));
}

TEST(textgen, test3) {
  std::map<prefix, std::vector<std::string>> statetab;
  prefix pref;
  pref.push_back("one");
  statetab[pref].push_back("two");
  EXPECT_EQ("two", statetab[pref][0]);
}

TEST(textgen, test4) {
  std::map<prefix, std::vector<std::string>> statetab;
  prefix pref;
  pref.push_back("one");
  prefVar.push_back("two");
  statetab[prefVar].push_back("three");
  std::string res = text_generating(&statetab, prefVar);
  EXPECT_EQ("one two three", res);
}

TEST(textgen, test5) {
  add_to_state_tab(&statetab, "C:/Users/Irina/tp-lab-8/src/input.txt");
  prefix pref;
  pref.push_back("computer");
  pref.push_back("pattern");
  bool flag = true;
  if (statetab.find(pref) == statetab.end()) {
    flag = false;
  }
  EXPECT_EQ(true, flag);
}