//  Copyright 2021 Nikita Naumov
#include "../include/textgen.h"

int main() {
    std::map<prefix, std::vector<std::string>> statetab;  //  current statetab
    std::string filename;
    std::cin >> filename;
    fulfilStatetab(filename, &statetab);
    printMap(&statetab);
    return 0;
}
