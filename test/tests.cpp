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