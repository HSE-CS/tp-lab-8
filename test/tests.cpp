// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>

#include <random>
 #include <string>
 #include <gtest/gtest.h>
 #include "textgen.h"

TEST(textgen, test1) {
  Analyze analyze;
  analyze.ReadFile();
      std::vector<std::deque
       <std::string>> pref;
 pref.reserve(analyze.statetab.size());
   for (auto const& key: analyze.statetab) {
    pref.push_back(key.first);
  }
  EXPECT_EQ(2, pref.at(0).size());
}
TEST(textgen, test2) {
  Analyze analyze;
  analyze.ReadFile();
  analyze.prefix.emplace_back("Который");
  analyze.prefix.emplace_back("построил");
  bool f = true;
  if ( analyze.statetab.find(analyze.prefix)
      == analyze.statetab.end() ) {
    f = false;
  }
  EXPECT_EQ(true, f);
}
TEST(testgen, test3) {
  Analyze analyze;
  analyze.ReadFile();
  analyze.prefix.emplace_back("часто"); 
  analyze.prefix.emplace_back("ворует");
  std::random_device rd;
  std::mt19937 mersenne(rd());
  size_t r_i = static_cast<size_t>(mersenne()
      % analyze.statetab.find
      (analyze.prefix)->second.size());
  EXPECT_EQ("пшеницу,",
            analyze.statetab.find
            (analyze.prefix)->second[r_i]);
}
TEST(textgen, test4) {
  Analyze analyze;
  analyze.ReadFile();
  analyze.prefix.emplace_back("А");
  analyze.prefix.emplace_back("это");
  std::random_device rd;
  std::mt19937 mersenne(rd());
  size_t r_i = static_cast<size_t>(mersenne()
      % analyze.statetab.find(analyze.prefix)
          ->second.size());
  EXPECT_EQ(true,
      analyze.statetab.find(analyze.prefix)
          ->second[r_i] == "пшеница,"
          ||
          analyze.statetab.find(analyze.prefix)
          ->second[r_i] == "весёлая");
}
TEST(textgen, test5) {
  Analyze analyze;
  analyze.ReadFile();
  analyze.Generate();
  EXPECT_EQ(true, analyze.text.size() > 100);
}