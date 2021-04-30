// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include <textgen.h>

TEST(MARKOV, mapgen1) {
  std::string text = "word1 word2 word3 word1 word2 word2 word2 word1 word1";
  size_t prefixSize = 1;

  WordMap map = {{"word1", {{"", 3}, {"word2", 2}, {"word1", 1}}},
                 {"word2", {{"", 4}, {"word3", 1}, {"word2", 2}, {"word1", 1}}},
                 {"word3", {{"", 1}, {"word1", 1}}}};

  ASSERT_EQ(generateWordMap(text, prefixSize).map, map);
}

TEST(MARKOV, mapgen2) {
  std::string text = "word1 word2 word3 word1 word2 word2";
  size_t prefixSize = 2;

  WordMap map = {
      {"word1 word2", {{"", 2}, {"word2", 1}, {"word3", 1}}},
      {"word2 word3", {{"", 1}, {"word1", 1}}},
      {"word3 word1", {{"", 1}, {"word2", 1}}},
  };

  ASSERT_EQ(generateWordMap(text, prefixSize).map, map);
}

TEST(MARKOV, mapgen3) {
  std::string text = "word1 word2 word3 word1 word2 word2";
  size_t prefixSize = 3;

  WordMap map = {
      {"word1 word2 word3", {{"", 1}, {"word1", 1}}},
      {"word2 word3 word1", {{"", 1}, {"word2", 1}}},
      {"word3 word1 word2", {{"", 1}, {"word2", 1}}},
  };

  ASSERT_EQ(generateWordMap(text, prefixSize).map, map);
}
