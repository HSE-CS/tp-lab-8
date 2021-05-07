// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>

#include "textgen.h"

TEST(test, test1) {
  prefix pref;
  EXPECT_EQ(true, pref.empty());
}

TEST(test, test2) {
  prefix pref;
  pref.push_back("a");
  pref.push_back("b");
  EXPECT_EQ(2, pref.size());
}

TEST(test, test3) {
  prefix pref;
  pref.push_back("a");
  pref.push_back("b");
  EXPECT_EQ("a", pref.at(0));
}

TEST(test, test4) {
  prefix pref;
  pref.push_back("a");
  pref.push_back("b");
  pref.pop_front();
  EXPECT_EQ("b", pref.at(0));
}

TEST(test, test5) {
  prefix pref;
  pref.push_back("a");
  statetab[pref].push_back("b");
  statetab[pref].push_back("c");
  EXPECT_EQ(2, statetab[pref].size());
}
