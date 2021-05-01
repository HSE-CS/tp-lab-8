// Copyright 2021 Longa_Bonga
#include <gtest/gtest.h>
#include "textgen.h"

TEST(textgen, test1) {
    std::map<prefix, std::vector<std::string>> statetab;
    prefix prefVar;
    prefVar.push_back("My");
    prefVar.push_back("Name");
    statetab[prefVar].push_back("is");
    std::string ans = generateText(&statetab, prefVar);
    EXPECT_EQ(ans, "My Name is");
}

TEST(textgen, test2) {
    std::map<prefix, std::vector<std::string>> statetab;
    prefix prefVar = {"Гарри", "Поттер"};
    fulfilStatetab(&statetab, "../Harry_Potter.txt");
    bool isExist = true;
    if (statetab.find(prefVar) == statetab.end()) {
        isExist = false;
    }
    EXPECT_EQ(true, isExist);
}

TEST(textgen, test3) {
    std::map<prefix, std::vector<std::string>> statetab;
    prefix prefVar = {"Я", "хотел"};
    fulfilStatetab(&statetab, "../Harry_Potter.txt");
    bool isExist = true;
    if (statetab.find(prefVar) == statetab.end()) {
        isExist = false;
    }
    EXPECT_EQ(false, isExist);
}

TEST(textgen, test4) {
    std::map<prefix, std::vector<std::string>> statetab;
    fulfilStatetab(&statetab, "../Harry_Potter.txt");
    prefix prefVar = {"Гарри", "Поттер"};
    std::string text = generateText(&statetab, prefVar);
    EXPECT_EQ(true, text.size() >= 1000);
}

TEST(textgen, test5) {
    std::map<prefix, std::vector<std::string>> statetab;
    prefix prefVar = {"Гарри", "Поттер"};
    fulfilStatetab(&statetab, "../Harry_Potter.txt");
    auto pos = statetab.find(prefVar);
    EXPECT_NE(statetab.end(), pos);
}
