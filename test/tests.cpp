// Copyright 2021 Egor Buzanov

#include <gtest/gtest.h>

#include "../include/textgen.h"

TEST(lab8, test1) {
  std::string text =
      "All our products are unique and hand selected by our chefs, who often \
      come from one of the region’s leading families.";
  std::stringstream strs(text);
  prefix words;
  while (strs >> text) {
    words.push_back(text + " ");
  }
  words.back() += "\n";
  EXPECT_EQ(21, words.size());
}

TEST(lab8, test2) {
  std::string text = "All our products are unique.";
  std::stringstream strs(text);
  prefix words;
  while (strs >> text) {
    words.push_back(text + " ");
  }
  words.back() += "\n";
  while (words.size() > NPREF) {
    prefix pref;
    for (size_t i = 0; i < NPREF; i++) {
      pref.push_back(words[i]);
    }
    statetab[pref].push_back(words[NPREF]);
    words.pop_front();
  }
  std::map<prefix, std::vector<std::string>> test_tab = {
      {{"All ", "our "}, {"products "}},
      {{"our ", "products "}, {"are "}},
      {{"products ", "are "}, {"unique. \n"}}};
  EXPECT_EQ(test_tab, statetab);
}

TEST(lab8, test3) {
  std::map<prefix, std::vector<std::string>> test_tab = {
      {{"All ", "our "}, {"products "}},
      {{"our ", "products "}, {"are "}},
      {{"products ", "are "}, {"unique. "}}};
  std::string word;
  std::random_device rd;
  std::mt19937 mersenne(rd());
  for (const auto& item : test_tab) {
    word = item.second[mersenne() % item.second.size()];
    break;
  }
  EXPECT_EQ("products ", word);
}

TEST(lab8, test4) {
  std::map<prefix, std::vector<std::string>> test_tab = {
      {{"All ", "our "}, {"products ", "test ", "cpp "}}};
  std::string word;
  std::random_device rd;
  std::mt19937 mersenne(rd());
  for (const auto& item : test_tab) {
    word = item.second[mersenne() % item.second.size()];
    break;
  }
  EXPECT_EQ(true, (word == "products " || word == "test " || word == "cpp "));
}

TEST(lab8, test5) {
  statetab = {{{"All ", "our "}, {"products "}},
              {{"our ", "products "}, {"are "}},
              {{"products ", "are "}, {"unique. "}}};
  std::string text = "All our products our products are products are unique. ";

  EXPECT_EQ(text, makeText());
}
