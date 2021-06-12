// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "../include/textgen.h"

TEST(task, test_1) {
    GenerationOfText test_1;
    std::string text_1 = "123 345 567 89";
    test_1.genTable(text_1);
    std::string result_1 = test_1.genText();
    EXPECT_EQ("123 345 567 89 ", result_1);
}

TEST(task, test_2) {
    GenerationOfText test_2;
    std::string text_2 = "123 456";
    test_2.genTable(text_2);
    std::string result_2 = test_2.genText();
    EXPECT_EQ("123 456 ", result_2);
}

TEST(task, test_3) {
    std::map<std::deque<std::string>, std::vector<std::string> > str_3;
    str_3[{"123", "567"}].push_back("234");
    GenerationOfText test_3 = GenerationOfText(str_3, { "123", "567", "234" });
    std::string result_3 = test_3.genText();
    EXPECT_EQ("123 567 234 ", result_3);
}

TEST(task, test_4) {
    GenerationOfText test_5;
    std::string text_5 = "a b c d";
    test_5.genTable(text_5);
    std::string result_5 = test_5.genText();
    EXPECT_EQ("a b c d ", result_5);
}
