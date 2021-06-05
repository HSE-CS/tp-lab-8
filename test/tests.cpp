// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>

#include "textgen.h"



TEST(textgen, text1){

    Markov_Model generator;
    generator.AddElements("source.txt");

    std::vector<prefix> prefixes;

    for (const auto& pairs:generator.state_tab){
        prefixes.push_back(pairs.first);
    }

    EXPECT_EQ(N_PREF, prefixes.at(0).size());
}

TEST(textgen, test2){

    Markov_Model generator;
    generator.AddElements("source.txt");

    prefix pref{"The", "catcher"};

    EXPECT_EQ(true, generator.state_tab.find(pref) != generator.state_tab.end());

}

TEST(textgen, test3){

    Markov_Model generator;
    generator.AddElements("source.txt");
    prefix pref{"The", "catcher"};
    std::vector <std::string> suffix{"in"};
    unsigned int index = rand() % suffix.size();
    std::string W3 = suffix[index];

    bool result = false;
    for(const auto& suf : suffix){
        if (W3 == suf){
            result = true;
            break;
        }
    }

    EXPECT_EQ(true, result);

}

TEST(textgen, test4){

    Markov_Model generator;
    generator.AddElements("source.txt");
    prefix pref {"I", "was"};
    std::vector <std::string> suffix{"doing", "way" };

    unsigned int index = rand() % suffix.size();
    std::string W3 = suffix[index];

    bool result = false;
    for(auto suf : suffix){
        if (W3 == suf){
            result = true;
            break;
        }
    }

    EXPECT_EQ(true, result);

}

TEST(textgen, test5){
    Markov_Model generator;
    generator.AddElements("source.txt");
    auto result = generator.GenerateText();
    EXPECT_EQ(true, result.size() > (unsigned long) 0.95*MAX_GEN);
}