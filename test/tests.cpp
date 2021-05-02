// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>

TEST(textgen, test1) {
  TextGen text1;
  text1.setPath("../src/input.txt");
  text1.ReadText();
  EXPECT_EQ(37, text1.getCount());
}

TEST(textgen, test2) {
  TextGen text2;
  text1.setPath("../src/input.txt");
  text1.ReadText();
  text1.makePairs();
  EXPECT_EQ("Nory was a Catholic because ", text1.createText(5));
}