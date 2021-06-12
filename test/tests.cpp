// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>

#include "textgen.h"

TEST(Test, Test1) {
    prefix pref;
    EXPECT_EQ(true, pref.empty());
}

TEST(Test, Test2) {
    prefix pref;
    pref.push_back("abcd");
    pref.push_back("efgh");
    EXPECT_EQ(2, pref.size());
}

TEST(Test, Test3) {
    prefix pref;
    pref.push_back("abc");
    statetab[pref].push_back("def");
    statetab[pref].push_back("ghi");
    statetab[pref].push_back("jkl");
    EXPECT_EQ(3, statetab[pref].size());
}

TEST(Test, Test4) {
    prefix pref;
    pref.push_back("abc");
    pref.push_back("def");
    pref.push_back("ghi");
    pref.pop_front();
    EXPECT_EQ("def", pref.at(0));
}

TEST(Test, Test5) {
    prefix pref;
    pref.push_back("abc");
    pref.push_back("def");
    EXPECT_EQ("abc", pref.at(0));
}