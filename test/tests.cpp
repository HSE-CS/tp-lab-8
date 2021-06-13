// Copyright Kasyanov 2021
#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <deque>
#include <map>
#include "../include/textgen.h"

TEST(set1, test1) {
    std::vector<std::string> words = {"foo", "boo", "doo"};
    auto table = createTable(words);
    EXPECT_EQ(1, table.size());
}

TEST(set1, test2) {
    std::vector<std::string> words = {"foo", "boo"};
    auto table = createTable(words);
    EXPECT_EQ(0, table.size());
}

TEST(set1, test3) {
    std::vector<std::string> words = {"foo", "boo", "doo"};
    auto table = createTable(words);
    prefix pref;
    pref.push_front("foo");
    pref.push_back("boo");
    std::vector<std::string> expected = {"doo"};
    EXPECT_EQ(expected, table[pref]);
}

TEST(set1, test4) {
    std::vector<std::string> words = {"foo", "boo", "doo", "poo"};
    auto table = createTable(words);
    EXPECT_EQ(2, table.size());
}

TEST(set1, test5) {
    std::vector<std::string> words = {"foo", "boo", "doo", "foo", "boo", "poo"};
    auto table = createTable(words);
    prefix pref;
    pref.push_front("foo");
    pref.push_back("boo");
    std::vector<std::string> expected = {"doo", "poo"};
    EXPECT_EQ(expected, table[pref]);
}
