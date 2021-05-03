// Copyright 2021 kisozinov
#include <gtest/gtest.h>
#include "textgen.h"

TEST(textgen, test1) {
    std::map<prefix, std::vector<std::string>> statetab;
    prefix pref;
    pref.push_back("A");
    pref.push_back("B");
    statetab[pref].push_back("C");
    std::string res = generateText(&statetab, pref);
    EXPECT_EQ(res, "A B C");
}

TEST(textgen, test2) {
    std::map<prefix, std::vector<std::string>> statetab;
    prefix pref = {"Sherlock", "Holmes"};
    fillStatetab(&statetab, "D:\Projects C\tp-lab8\input2.txt");
    bool isExist = true;
    if (statetab.find(pref) == statetab.end()) {
        isExist = false;
    }
    EXPECT_EQ(true, isExist);
}

TEST(textgen, test3) {
    std::map<prefix, std::vector<std::string>> statetab;
    prefix pref = {"Privet", "Poka"};
    fillStatetab(&statetab, "D:\Projects C\tp-lab8\input2.txt");
    bool isExist = true;
    if (statetab.find(pref) == statetab.end()) {
        isExist = false;
    }
    EXPECT_EQ(false, isExist);
}

TEST(textgen, test4) {
    std::map<prefix, std::vector<std::string>> statetab;
    fulfillStatetab(&statetab, "D:\Projects C\tp-lab8\input2.txt");
    prefix pref = {"continued", "to"};
    std::string text = generateText(&statetab, pref);
    EXPECT_EQ(true, text.size() >= 1000);
}

TEST(textgen, test5) {
    std::map<prefix, std::vector<std::string>> statetab;
    prefix pref = {"Why", "has"};
    fillStatetab(&statetab, "D:\Projects C\tp-lab8\input2.txt");
    auto pos = statetab.find(pref);
    EXPECT_NE(statetab.end(), pos);
}
