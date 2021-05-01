// Copyright 2021 Kuznetsov Mikhail
#include "gtest/gtest.h"
#include "textgen.h"
#include <iterator>
#include <algorithm>

TEST(TextGenTest, test1) {
  std::map<prefix, std::vector<std::string>> statetab;
  createStateTab("../data/input.txt", statetab);
  EXPECT_EQ(2, (*statetab.begin()).size());
}

TEST(TextGenTest, test2) {
  std::map<prefix, std::vector<std::string>> statetab;
  prefix pref;
  pref.push_back("ten");
  pref.push_back("plus");
  statetab[pref].push_back("ten");
  std::string result;
  auto start = _statetab.find(pref);
  sstd::string suff = start->second[0];
    result += suff + ' ';
  EXPECT_EQ(result, "ten plus ten");
}

TEST(TextGenTest, test3) {
  std::map<prefix, std::vector<std::string>> statetab;
  prefix pref;
  pref.push_back("summer");
  pref.push_back("is");
  statetab[pref].push_back("coming");
  std::string result = generateText(statetab, pref);
  EXPECT_EQ(result, "summer is coming");
}

TEST(TextGenTest, test4) {
  std::map<prefix, std::vector<std::string>> statetab;
  prefix pref;
  pref.push_back("summer");
  pref.push_back("is");
  std::vector <string> suff = {"coming", "cool", "hot"};
  statetab[pref] = suff;
  std::string result = generateText(statetab, pref);
  EXPECT_EQ(true, result == "summer is coming" ||
                  result == "summer is cool" ||
                  result == "summer is hot" );
}

TEST(TextGenTest, test5) {
  std::map<prefix, std::vector<std::string>> statetab;
  prefix start, pref;
  pref.push_back("summer");
  pref.push_back("is");
  start = pref;
  statetab[pref].push_back("coming");
  pref.pop_back("coming");
  pref.pop_front();
  statetab[pref].push_back("tomorrow");
  std::string result = generateText(statetab, start);
  EXPECT_EQ(true, result == "summer is coming tomorrow");
}

TEST(TextGenTest, test6) {
  std::map<prefix, std::vector<std::string>> statetab;
  prefix start, pref;
  pref.push_back("summer");
  pref.push_back("is");
  statetab[pref].push_back("coming");
  pref.pop_back("coming");
  pref.pop_front();
  start = pref;
  statetab[pref].push_back("tomorrow");
  std::string result = generateText(statetab, start);
  EXPECT_EQ(true, result == "is coming tomorrow");
}

TEST(TextGenTest, test7) {
  std::map<prefix, std::vector<std::string>> statetab;
  createStateTab("../data/input.txt", statetab;
  std::string result = generateText(statetab);
  EXPECT_EQ(true, (int)count(result.begin(), result.end(), ' ') <= 999);
}


