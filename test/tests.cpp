// Copyright Kasyanov 2021
#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <deque>
#include <map>
#include "../include/textgen.h"

TEST(set1, test1) {
    auto table = createTable(createWordVector("../text.txt"));
    prefix testPrefix = {"Вот", "кот"};
    bool isInTable = (table.find(testPrefix) != table.end()) ? true : false;
    EXPECT_EQ(true, isInTable);
}
