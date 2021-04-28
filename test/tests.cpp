// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "textgen.h"

TEST(textgen, test1) {
    std::map<prefix, std::vector<std::string>> statetabb;
    preprocess_table("BonesLyricsClean.txt", &statetabb);
    std::vector<prefix> k;
    k.reserve(statetabb.size());
    for (auto const& key: statetabb) {
        k.push_back(key.first);
    }
    EXPECT_EQ(3, k.at(0).size());
}

TEST(textgen, test2) {
    std::map<prefix, std::vector<std::string>> statetabb;
    preprocess_table("BonesLyricsClean.txt", &statetabb);
    prefix p{"sittin", "all", "alone"};
    bool f = true;
    if ( statetabb.find(p) == statetabb.end() ) {
        f = false;
    }
    EXPECT_EQ(true, f);
}

TEST(textgen, test3) {
    std::map<prefix, std::vector<std::string>> statetabb;
    preprocess_table("BonesLyricsClean.txt", &statetabb);
    prefix p{"artesian", "water", "when"};
    EXPECT_EQ(0, generate(p, &statetabb).rfind("artesian water when im", 0));
}

TEST(textgen, test4) {
    std::map<prefix, std::vector<std::string>> statetabb;
    preprocess_table("BonesLyricsClean.txt", &statetabb);
    prefix p{"press", "your", "luck"};
    auto text = generate(p, &statetabb);
    int res1 = text.rfind("press your luck bitch", 0);
    int res2 = text.rfind("press your luck and", 0);
    EXPECT_EQ(true, res1 == 0 || res2 == 0);
}

TEST(textgen, test5) {
    std::map<prefix, std::vector<std::string>> statetabb;
    preprocess_table("BonesLyricsClean.txt", &statetabb);
    prefix st{"johnny", "cage", "black"};
    auto text = generate(st, &statetabb);
    EXPECT_EQ(true, text.size() > 80);
}
