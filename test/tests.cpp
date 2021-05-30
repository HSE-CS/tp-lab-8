// Copyright 2021 by Liza
#include "textgen.h"

TEST(task, test_1) {
TextGeneration test_1;
std::string text_1 = "pri ve t";
test_1.MakingTheTable(text_1);
std::string result_1 = test_1.TextGeneration();
char* ch_1 = new char[result_1.size() + 1];
strcpy(ch_1, result_1.c_str());
EXPECT_EQ("pri ve t ", ch_1);}
TEST(task, test_2) {
TextGeneration test_2;
std::string text_2 = "po ka";
test_2.MakingTheTable(text_2);
std::string result_2 = test_2.TextGeneration();
char* ch_2 = new char[result_2.size() + 1];
strcpy(ch_2, result_2.c_str());
EXPECT_EQ("po ka ", ch_2);}
TEST(task, test_3) {
std::map<std::deque<std::string>, std::vector<std::string> > str_3;
str_3[{"123", "567"}].push_back("234");
TextGeneration test_3 = TextGeneration(str_3, { "123","567","234" });
std::string result_3 = test_3.TextGeneration();
char* ch_3 = new char[result_3.size() + 1];
strcpy(ch_3, result_3.c_str());
EXPECT_EQ("123 567 234 ", ch_3);}
TEST(task, test_4) {
std::map<std::deque<std::string>, std::vector<std::string> > str_4;
str_4[{"123", "456"}].push_back("777");
str_4[{"123", "456"}].push_back("666");
str_4[{"123", "456"}].push_back("555");
TextGeneration test_4 = TextGeneration(str_4, { "123","456","777", "666", "555" });
std::string result_4 = test_4.NewText();
char* ch_4 = new char[result_4.size() + 1];
strcpy(ch_4, result_4.c_str());
EXPECT_EQ("123 456 555 ", ch_4);}
TEST(task, test_5) {
TextGeneration test_5;
std::string text_5 = "1 2 3 4";
test_5.MakingTheTable(text_5);
std::string result_5 = test_5.NewText();
char* ch_5 = new char[result_5.size() + 1];
strcpy(ch_5, result_5.c_str());
EXPECT_EQ("1 2 3 4 ", ch_5);}
