// Copyright Kasyanov 2021
#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <deque>
#include <map>
#include "../include/textgen.h"

TEST(set1, test1) {
    auto table = createTable(createWordVector("../text.txt"));
    prefix testPrefix = {"Вот", "кот"};
    bool isInTable = (table.find(testPrefix) != table.end()) ? true : false;
    EXPECT_EQ(true, isInTable);
}

TEST(set1, test2) {
    auto table = createTable(createWordVector("../text.txt"));
    prefix testPrefix = {"Р", "Л"};
    bool isInTable = (table.find(testPrefix) != table.end()) ? true : false;
    EXPECT_EQ(false, isInTable);
}

TEST(set1, test3) {
    std::map<prefix, std::vector<std::string>> testTable;
    prefix testPrefix = {"Вот", "кот"};
    testTable[testPrefix].push_back("который");
    auto text = generateText(testTable);
    EXPECT_EQ("Вот кот который.", text);
}

TEST(set1, test4) {
    std::vector<std::string> words = {"Вот", "кот", "который"};
    auto table = createTable(words);
    prefix testPrefix = {"Вот", "кот"};
    std::vector<std::string> expected = {"который"};
    EXPECT_EQ(expected, table[testPrefix]);
}

TEST(set1, test5) {
    std::vector<std::string> words = {"Вот", "кот", "который"};
    auto table = createTable(words);
    prefix testPrefix = {"кот", "который"};
    EXPECT_EQ(true, table[testPrefix].empty());
}
