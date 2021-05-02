// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>

#include "../include/textgen.h"

TEST(textgen, test1) {
  MarkovChain ex1;
  int a = ex1.MakeTableInt("text.txt");
  EXPECT_EQ(3, a);
}

/*TEST(textgen, test2) {
  MarkovChain a;
  a.MakeTable("input.txt");
  std::string b = a.CreateNewText();
  std::cout << b;
  std::cout << a.MakeTableInt("input.txt") << std::endl;
  EXPECT_EQ(false, a);
}*/