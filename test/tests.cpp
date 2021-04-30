// Copyright 2021 GHA Test Team

#include "textgen.h"

#include <gtest/gtest.h>


TEST(set1, test1) {
    int len_pref = 2;
    std::vector<std::string> test_vect;
    test_vect.push_back("Hi");
    test_vect.push_back("this");
    test_vect.push_back("is");
    test_vect.push_back("test");
    Linker test_linker(len_pref, test_vect);
    std::map<prefix,
        std::vector<std::string>>::iterator it = test_linker.getTable().begin();
    prefix pref_chek = it->first;
    EXPECT_EQ(len_pref, pref_chek.size());
}

TEST(set1, test2) {
    int len_pref = 1;
    std::vector<std::string> test_vect;
    test_vect.push_back("Hi");
    test_vect.push_back("this");
    test_vect.push_back("is");
    test_vect.push_back("test");
    Linker test_linker(len_pref, test_vect);
    std::map<prefix,
        std::vector<std::string>>::iterator it = test_linker.getTable().begin();
    prefix pref_chek = it->first;
    EXPECT_EQ(len_pref, pref_chek.size());
}

TEST(set2, test1) {
    int len_pref = 1;
    std::vector<std::string> test_vect;
    test_vect.push_back("Hi");
    test_vect.push_back("this");
    test_vect.push_back("is");
    test_vect.push_back("test");
    Linker test_linker(len_pref, test_vect);
    std::map<prefix,
        std::vector<std::string>>::iterator it = test_linker.getTable().begin();
    prefix pref_chek = it->first;
    std::vector<std::string> suf_chek = it->second;
    EXPECT_EQ(pref_chek.front(), "Hi");
    EXPECT_EQ(suf_chek.front(), "this");
}

TEST(set2, test2) {
    int len_pref = 2;
    std::vector<std::string> test_vect;
    test_vect.push_back("Hi");
    test_vect.push_back("this");
    test_vect.push_back("is");
    test_vect.push_back("test");
    Linker test_linker(len_pref, test_vect);
    std::map<prefix,
        std::vector<std::string>>::iterator it = test_linker.getTable().begin();
    prefix pref_chek = it->first;
    std::vector<std::string> suf_chek = it->second;
    EXPECT_EQ(pref_chek.front(), "Hi");
    EXPECT_EQ(pref_chek.back(), "this");
    EXPECT_EQ(suf_chek.front(), "is");
}

TEST(set3, test1) {
    int len_pref = 2;
    std::vector<std::string> test_vect;
    test_vect.push_back("Hi");
    test_vect.push_back("this");
    test_vect.push_back("is");
    test_vect.push_back("test");
    Linker test_linker(len_pref, test_vect);
    std::map<prefix,
        std::vector<std::string>>::iterator it = test_linker.getTable().begin();
    prefix pref_chek = it->first;
    std::vector<std::string> suf_chek = it->second;
    Generator test_gen(len_pref, 3, test_linker.getTable());
    std::string result = test_gen.find_suf_for_pref(pref_chek);
    EXPECT_EQ(result, "is");
}

TEST(set3, test2) {
    int len_pref = 1;
    std::vector<std::string> test_vect;
    test_vect.push_back("Hi");
    test_vect.push_back("this");
    test_vect.push_back("is");
    test_vect.push_back("test");
    Linker test_linker(len_pref, test_vect);
    std::map<prefix,
        std::vector<std::string>>::iterator it = test_linker.getTable().begin();
    prefix pref_chek = it->first;
    std::vector<std::string> suf_chek = it->second;
    Generator test_gen(len_pref, 3, test_linker.getTable());
    std::string result = test_gen.find_suf_for_pref(pref_chek);
    EXPECT_EQ(result, "this");
}

TEST(set4, test1) {
    int len_pref = 1;
    std::vector<std::string> test_vect;
    test_vect.push_back("Hi");
    test_vect.push_back("this");
    test_vect.push_back("Hi");
    test_vect.push_back("test");
    Linker test_linker(len_pref, test_vect);
    std::map<prefix,
        std::vector<std::string>>::iterator it = test_linker.getTable().begin();
    prefix pref_chek = it->first;
    std::vector<std::string> suf_chek = it->second;
    Generator test_gen(len_pref, 3, test_linker.getTable());
    std::string result = test_gen.find_suf_for_pref(pref_chek);
    EXPECT_EQ(result, "test");
}

TEST(set5, test1) {
    int len_pref = 1;
    std::vector<std::string> test_vect;
    test_vect.push_back("Hi");
    test_vect.push_back("this");
    test_vect.push_back("is");
    test_vect.push_back("test");
    test_vect.push_back("I");
    test_vect.push_back("think");
    test_vect.push_back("it");
    test_vect.push_back("is");
    test_vect.push_back("good");
    test_vect.push_back("job");
    Linker test_linker(len_pref, test_vect);
    std::map<prefix,
        std::vector<std::string>>::iterator it = test_linker.getTable().begin();
    prefix pref_chek = it->first;
    std::vector<std::string> suf_chek = it->second;
    Generator test_gen(len_pref, 5, test_linker.getTable());
    EXPECT_EQ(result, "Hi this is good job");
}
