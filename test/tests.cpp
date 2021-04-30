// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "textgen.h"

TEST(GenTests, test1) {
    std::string path = "include/text.txt";
    std::map<std::deque<std::string>, std::vector<std::string>> statetab = createPrefix(path);
    std::vector<std::deque<std::string>> k;
    k.reserve(statetab.size());
    for (auto const& key: statetab) {
        k.push_back(key.first);
    }
    EXPECT_EQ(2, k.at(1).size());
}

TEST(GenTests, test2) {
    std::string path = "include/text.txt";
    std::map<std::deque<std::string>, std::vector<std::string>> statetab = createPrefix(path);
    std::deque<std::string> pr{"mutual", "funds"};
    
    EXPECT_EQ("geared", statetab[pr].at(0));
}

TEST(GenTests, test3) {
    std::string path = "include/text.txt";
    std::map<std::deque<std::string>, std::vector<std::string>> statetab = createPrefix(path);
    std::deque<std::string> pr{"on", "the"};

    EXPECT_EQ("long", statetab[pr].at(1));
}

TEST(GenTests, test4) {
    std::string path = "include/text.txt";
    std::map<std::deque<std::string>, std::vector<std::string>> statetab = createPrefix(path);
    std::deque<std::string> pr{"on", "the"};

    EXPECT_EQ(2, statetab[pr].size());
}

TEST(GenTests, test5) {
    std::string path = "include/text.txt";
    std::map<std::deque<std::string>, std::vector<std::string>> statetab = createPrefix(path);
    generateText("text2.txt", statetab);
    std::string line;
    std::ifstream in("include/text2.txt");
    int count = 0;
    while (getline(in, line)) {
        count += line.length();
    }
    int flag = 0;
    if (count > 20) {
        flag = 1;
    }
    EXPECT_EQ(1, flag);
}
