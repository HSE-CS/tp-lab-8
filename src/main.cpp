//  Copyright 2021 Nikita Naumov
#include "../include/textgen.h"

int main() {
    srand(time(NULL));
    std::map<prefix, std::vector<std::string>> statetab;  //  current statetab
    std::string filename;
    std::cin >> filename;
    fulfilStatetab(filename, &statetab);
    printMap(&statetab);
    prefix start;
    start.push_back(static_cast<std::string>("worth"));
    start.push_back(static_cast<std::string>("it"));
    std::string output = generateText(&statetab, start);
    std::ofstream outputFile("output.txt");
    outputFile << output;
    return 0;
}
