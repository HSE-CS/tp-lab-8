//  Copyright 2021 Longa_Bonga
#include "textgen.h"

int main() {
    srand(time(NULL));
    std::map<prefix, std::vector<std::string>> statetab;
    fulfilStatetab(&statetab, "Harry_Potter.txt");
    printMap(&statetab);
    prefix start;
    std::cout << "Enter the start (" << NPREF << " words)"  << std::endl;
    for (size_t i = 0; i < NPREF; ++i) {
        std::string buffer;
        std::cin >> buffer;
        start.push_back(buffer);
        buffer.clear();
    }
    std::string output = generateText(&statetab, start);
    std::cout << output.size() << std::endl;
    std::ofstream outputFile("output.txt");
    outputFile << output;
    return 0;
}
