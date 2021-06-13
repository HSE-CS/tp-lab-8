// Copyright Leonidek23 2021

#include "gtest/gtest.h"
#include "textgen.h"
#include <iterator>
#include <algorithm>
#include <fstream>

TEST(addtable, TEST1) {
std::map<prefix, std::vector<std::string>> tab;
AddTable("src/input.txt", &tab);
EXPECT_EQ(2, (tab.begin()->first).size());
}

TEST(addtable, TEST2) {
std::map<prefix, std::vector<std::string>> tab;
AddTable("src/input.txt", &tab);
EXPECT_EQ("- as", tab.begin()->first[0] + " " + tab.begin()->first[1]);
}

TEST(GenerateTextTableTest, TEST3) {
std::map<prefix, std::vector<std::string>> tab;
AddTable("src/input.txt", &tab);
auto str = Text(&tab);
prefix pref = { "fierce", "ships"};
auto pos = tab.find(pref);
EXPECT_EQ(tab.end(), pos);
}

TEST(addtable, TEST4) {
std::map<prefix, std::vector<std::string>> tab;
AddTable("src/input.txt", &tab);
prefix testPrefix = { "I", "Robot" };
bool isInTable = (tab.find(testPrefix) != tab.end()) ? true : false;
EXPECT_EQ(false, isInTable);
}

TEST(GenerateTextTableTest, TEST5) {
std::map<prefix, std::vector<std::string>> tab;
AddTable("src/input.txt", &tab);
std::ifstream input("src/output.txt");
auto str = Text(&tab);
std::string result = "";
std::string buf = "";
for (int i = 0; i < 7; i++) {
input >> buf;
result += buf + " ";
}
EXPECT_EQ("You think ", result);
}
