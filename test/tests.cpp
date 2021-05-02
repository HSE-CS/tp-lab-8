// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>

#include "../include/textgen.h"

TEST(TextGenerator, test1) {
  prefix pr;
  EXPECT_EQ(true, pr.empty());
}

TEST(TextGenerator, test2) {
  prefix pr;
  pr.push_back("test #2");
  EXPECT_EQ(1, pr.size());
}

TEST(TextGenerator, test3) {
  prefix pr;
  pr.push_back("test #3");
  pr.push_back("number 3");
  pr.pop_front();
  EXPECT_EQ("number 3", pr.at(0));
}

TEST(TextGenerator, test4) {
  prefix pr;
  pr.push_back("test #4");
  statetab[pr].push_back("number 4");
  EXPECT_EQ("number 4", statetab[pr][0]);
}

TEST(TextGenerator, test5) {
  prefix pr;
  pr.push_back("test #5");
  statetab[pr].push_back("number 5");
  EXPECT_EQ(1, statetab[pr].size());
}
