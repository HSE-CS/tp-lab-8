//  Copyright 2021 Nikita Naumov
#include "../include/textgen.h"

int main() {
    srand(time(NULL));
    std::map<prefix, std::vector<std::string>> statetab;  //  current statetab
    std::string filename;
    std::cout << "Enter the source file name" << std::endl;
    std::cin >> filename;
    fulfilStatetab(&statetab, filename);
    printMap(&statetab);
    prefix start;
    std::cout << "Enter the start of generation (" << NPREF << " word(s))"
                                                            << std::endl;
    for (size_t i = 0; i < NPREF; ++i) {
        std::string str;
        std::cin >> str;
        start.push_back(str);
        str.clear();
    }
    std::string output = generateText(&statetab, start);
    std::ofstream outputFile("output.txt");
    outputFile << output;
    return 0;
}
