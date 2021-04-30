// Copyright 2021 MalininDmitry

#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include "textgen.h"


int main() {
    std::string path = "text.txt";
    std::map<std::deque<std::string>, std::vector<std::string>> statetab = createPrefix(path);
    generateText("text2.txt", statetab);
    return 0;
}
