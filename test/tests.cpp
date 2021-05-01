// Copyright 2021 Schenikova

#include <gtest/gtest.h>

#include "../include/textgen.h"

TEST(textgen, test1) {
  prefix pr;
  EXPECT_EQ(true, pr.empty());
}

TEST(textgen, test2) {
  prefix pr;
  pr.push_back("test");
  pr.push_back("testik");
  EXPECT_EQ(2, pr.size());
}

TEST(textgen, test3) {
  prefix pr;
  pr.push_back("Hello");
  pr.push_back("world");
  EXPECT_EQ("Hello", pr.at(0));
}

TEST(textgen, test4) {
  prefix pr;
  pr.push_back("test");
  statetab[pr].push_back("number 4");
  EXPECT_EQ(1, statetab[pr].size());
}

TEST(textgen, test5) {
  prefix pr;
  pr.push_back("Hello");
  statetab[pr].push_back("World");
  EXPECT_EQ("World", statetab[pr][0]));
}
