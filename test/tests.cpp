//  Copyright Baklanov 2021
#include "../include/Textgen.h"
#include <gtest/gtest.h>
#include <string>
#include <iostream>

TEST(Train, TEST1) {
    std::map<prefix, std::vector<std::string> > statetab;
    const int NPREF = 2;
    const int MAXGEN = 1000;
    std::string fin = "text.txt";
    statetab = makeStatetab(NPREF, MAXGEN, fin);
    prefix startPref = { "There", "are" };
    auto it = statetab.find(startPref);
    EXPECT_EQ(NPREF, it->first.size());
}

TEST(Train, TEST2) {
    std::map<prefix, std::vector<std::string> > statetab;
    const int NPREF = 2;
    const int MAXGEN = 1000;
    std::string fin = "text.txt";
    statetab = makeStatetab(NPREF, MAXGEN, fin);
    prefix startPref = { "There", "are" };
    auto it = statetab.find(startPref);
    std::string somestring = it->first[0];
    somestring += ' ';
    somestring += it->first[1];
    somestring += ' ';
    somestring += generateText(&statetab, &startPref);
    EXPECT_EQ("There are five", somestring);
}

TEST(Train, TEST3) {
    std::map<prefix, std::vector<std::string> > statetab;
    const int NPREF = 2;
    const int MAXGEN = 1000;
    std::string fin = "text.txt";
    statetab = makeStatetab(NPREF, MAXGEN, fin);
    prefix startPref = { "There", "are" };
    auto it = statetab.find(startPref);
    std::string somestring = it->first[0];
    somestring += ' ';
    somestring += it->first[1];
    somestring += ' ';
    somestring += generateText(&statetab, &startPref);
    EXPECT_EQ("There are five", somestring);
}

TEST(Train, TEST4) {
    std::map<prefix, std::vector<std::string> > statetab;
    prefix startPref = { "There", "are" };
    std::vector<std::string> suffix;
    suffix.push_back("first");
    suffix.push_back("second");
    statetab.emplace(startPref, suffix);
    std::string somestring = generateText(&statetab, &startPref);
    EXPECT_EQ(true, somestring);
}

TEST(Train, TEST5) {
    std::map<prefix, std::vector<std::string> > statetab;
    const int NPREF = 2;
    const int MAXGEN = 1000;
    std::string fin = "text.txt";
    statetab = makeStatetab(NPREF, MAXGEN, fin);
    prefix startPref = { "There", "are" };
    auto it = statetab.find(startPref);
    EXPECT_EQ(NPREF, it->first.size());
}
