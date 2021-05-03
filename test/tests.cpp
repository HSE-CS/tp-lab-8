// Copyright 2021 Rogov Andrey
#include <gtest/gtest.h>

#include "../include/textgen.h"

TEST(textgen, test1) {
    prefix pref;
    EXPECT_EQ(true, pref.empty());
}

TEST(textgen, test2) {
    prefix pref;
    pref.push_back("test");
    pref.push_back("testik");
    EXPECT_EQ(2, pref.size());
}

TEST(textgen, test3) {
    prefix pref;
    pref.push_back("Hello");
    pref.push_back("world");
    EXPECT_EQ("Hello", pref.at(0));
}

TEST(textgen, test4) {
    prefix pref;
    pref.push_back("Hello");
    statetab[pref].push_back("World");
    EXPECT_EQ(1, statetab[pref].size());
}

TEST(textgen, test5) {
    prefix pref;
    pref.push_back("Hello");
    statetab[pref].push_back("World");
    EXPECT_EQ("World", statetab[pref][0]);
}
