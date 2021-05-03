//  Copyright 2021 kisozinov
#include "textgen.h"

int main() {
    srand(time(NULL));
    std::map<prefix, std::vector<std::string>> statetab;
    fillStatetab(&statetab, "input2.txt");
    printMap(&statetab);
    prefix start;
    std::cout << "Enter first " << NPREF << " words:"  << std::endl;
    for (size_t i = 0; i < NPREF; ++i) {
        std::string word;
        std::cin >> word;
        start.push_back(word);
        word.clear();
    }
    std::string output = generateText(&statetab, start);
    std::ofstream outputFile("output.txt");
    outputFile << output;
    return 0;
}
