// Copyright 2021 Nikita Naumov
#include <gtest/gtest.h>
#include "../include/textgen.h"

TEST(textgen, test1) {
    std::map<prefix, std::vector<std::string>> statetab;
    prefix prefVar;
    prefVar.push_back("Hello");
    prefVar.push_back("World");
    statetab[prefVar].push_back("Hahah");
    std::string ans = generateText(&statetab, prefVar);
    EXPECT_EQ(ans, "Hello World Hahah");
}

TEST(textgen, test2) {
    std::map<prefix, std::vector<std::string>> statetab;
    prefix prefVar = {"your", "waist"};
    fulfilStatetab(&statetab, "/home/runner/work/tp-lab-8/tp-lab-8/src/text.txt");
    bool isExist = true;
    if (statetab.find(prefVar) == statetab.end()) {
        isExist = false;
    }
    EXPECT_EQ(true, isExist);
}

TEST(textgen, test3) {
    std::map<prefix, std::vector<std::string>> statetab;
    prefix prefVar = {"I", "waist"};
    fulfilStatetab(&statetab, "/home/runner/work/tp-lab-8/tp-lab-8/src/text.txt");
    bool isExist = true;
    if (statetab.find(prefVar) == statetab.end()) {
        isExist = false;
    }
    EXPECT_EQ(false, isExist);
}

TEST(textgen, test4) {
    std::map<prefix, std::vector<std::string>> statetab;
    fulfilStatetab(&statetab, "/home/runner/work/tp-lab-8/tp-lab-8/src/text.txt");
    prefix prefVar = {"your", "waist"};
    std::string text = generateText(&statetab, prefVar);
    EXPECT_EQ(true, text.size() == 1000);
}

TEST(textgen, test5) {
    std::map<prefix, std::vector<std::string>> statetab;
    prefix prefVar = {"your", "waist"};
    fulfilStatetab(&statetab, "/home/runner/work/tp-lab-8/tp-lab-8/src/text.txt");
    auto pos = statetab.find(prefVar);
    EXPECT_NE(statetab.end(), pos);
}
