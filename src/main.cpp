// Copyright Leonidek23 2021

#include "textgen.h"
#include <deque>
#include <string>
#include <vector>
#include <map>
#include <fstream>

int main() {
    std::map<prefix, std::vector<std::string>> statetab;
    AddTable("input.txt", &statetab);
    std::ifstream input("output.txt");
    auto str = Text(&statetab);
    std::string result = "";
    std::string bufer = "";
    for (int i = 0; i < 8; i++) {
        input >> bufer;
        result += bufer + " ";
    }
}
