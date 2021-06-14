// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>

#include "textgen.h"

TEST(tests, test1) {
    prefix p;
    p.push_front("Hello");
    EXPECT_EQ(1, p.size());
}

TEST(tests, test2) {
    prefix p;
    p.push_back("Hello");
    p.push_front("World");
    EXPECT_EQ(2, p.size());
}

TEST(tests, test3) {
    prefix p;
    EXPECT_EQ(0, p.size());
}

TEST(tests, test4) {
    prefix p;
    p.push_front("Hello");
    p.push_front("World");
    p.pop_back();
    EXPECT_EQ("Hello", p[0]);
}

TEST(tests, test5) {
    prefix p;
    p.push_back("Hello");
    statetab[p].push_back("World");
    EXPECT_EQ(1, statetab[p].size());
}
