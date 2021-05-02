// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "../include/textgen.h";

TEST(task, test_1) {
    GenerationOfText test_1;
    std::string text_1 = "123 345 567 89";
    test_1.MakingTheTable(text_1);
    std::string result_1 = test_1.GenerationNewText();
    char* ch_1 = new char[result_1.size() + 1];
    strcpy(ch_1, result_1.c_str());
    EXPECT_EQ("123 345 567 89", ch_1);
}

TEST(task, test_2) {
    GenerationOfText test_2;
    std::string text_2 = "123 456";
    test_2.MakingTheTable(text_2);
    std::string result_2 = test_2.GenerationNewText();
    char* ch_2 = new char[result_2.size() + 1];
    strcpy(ch_2, result_2.c_str());
    EXPECT_EQ("123 456", ch_2);
}

TEST(task, test_3) {
    std::map<std::deque<std::string>, std::vector<std::string> > str_3;
    str_3[{"123", "567"}].push_back("234");
    GenerationOfText test_3 = GenerationOfText(str_3, { "123","567","234" });
    std::string result_3 = test_3.GenerationNewText();
    char* ch_3 = new char[result_3.size() + 1];
    strcpy(ch_3, result_3.c_str());
    EXPECT_EQ("123 567 234", ch_3);
}

TEST(task, test_4) {
    std::map<std::deque<std::string>, std::vector<std::string> > str_4;
    str_4[{"123", "456"}].push_back("111");
    str_4[{"123", "456"}].push_back("0234");
    str_4[{"123", "456"}].push_back("8645");
    GenerationOfText test_4 = GenerationOfText(str_4, { "123","456","111", "0234", "8645" });
    std::string result_4 = test_4.GenerationNewText();
    char* ch_4 = new char[result_4.size() + 1];
    strcpy(ch_4, result_4.c_str());
    EXPECT_EQ("123 456 8645", ch_4);
}

TEST(task, test_5) {
    GenerationOfText test_5;
    std::string text_5 = "a b c d";
    test_5.MakingTheTable(text_5);
    std::string result_5 = test_5.GenerationNewText();
    char* ch_5 = new char[result_5.size() + 1];
    strcpy(ch_5, result_5.c_str());
    EXPECT_EQ("a b c d", ch_5);
}
