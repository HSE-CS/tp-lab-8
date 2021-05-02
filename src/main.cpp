// Copyright 2021 Vlad

#include "textgen.h"
#include <deque>
#include <string>
#include <vector>
#include <map>
#include <fstream>

int main() {
    std::map<prefix, std::vector<std::string>> statetab;
    createStateTable("input.txt", &statetab);
    std::ifstream input("output.txt");
    auto str = generateText(&statetab);
    std::string result = "";
    std::string buf = "";
    for (int i = 0; i < 7; i++) {
        input >> buf;
        result += buf + " ";
    }
}
