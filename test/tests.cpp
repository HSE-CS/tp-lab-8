// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "textgen.h"

TEST(textgen, test1) {
  TextGen text1;
  text1.setPath("../src/input.txt");
  text1.ReadText();
  EXPECT_EQ(37, text1.getCount());
}

TEST(textgen, test2) {
  TextGen text2;
  text2.setPath("../src/input.txt");
  text2.ReadText();
  text2.makePairs();
  EXPECT_EQ("Nory was a Catholic because ", text2.createText(5));
}