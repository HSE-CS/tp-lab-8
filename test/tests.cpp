// Copyright 2021 Vlad

#include "gtest/gtest.h"
#include "textgen.h"
#include <iterator>
#include <algorithm>
#include <fstream>

TEST(CreateStateTableTest, TEST1) {
    std::map<prefix, std::vector<std::string>> statetab;
    createStateTab("../input.txt", &statetab);
    EXPECT_EQ(2, (statetab.begin()->first).size());
}

TEST(CreateStateTableTest, TEST2) {
    std::map<prefix, std::vector<std::string>> statetab;
    createStateTab("../input.txt", &statetab);
    EXPECT_EQ("- as", statetab.begin()->first[0] + " " + statetab.begin()->first[1]);
}

TEST(GenerateTextTableTest, TEST3) {
    std::map<prefix, std::vector<std::string>> statetab;
    createStateTab("../input.txt", &statetab);
    auto str = generateText(&statetab);
    prefix pref = { "extreme", "specialization"};
    auto pos = statetab.find(pref);
    EXPECT_EQ(statetab.end(), pos);
}

TEST(CreateStateTableTest, TEST4) {
    std::map<prefix, std::vector<std::string>> statetab;
    createStateTab("../input.txt", &statetab);
    prefix testPrefix = { "I", "Robot" };
    bool isInTable = (table.find(testPrefix) != table.end()) ? true : false;
    EXPECT_EQ(false, isInTable);
}

TEST(GenerateTextTableTest, TEST5) {
    std::map<prefix, std::vector<std::string>> statetab;
    createStateTab("../input.txt", &statetab);
    std::ifstream input("../output.txt");
    auto str = generateText(&statetab);
    std::string result = "";
    std::string buf = "";
    for (int i = 0; i < 7; i++) {
        input >> buf;
        result += buf + " ";
    }
    EXPECT_EQ("AT MY NOTES AND I DIDN'T LIKE ", result);
}
