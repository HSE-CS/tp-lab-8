//  Copyright 2021 Nikita Naumov
#include "../include/textgen.h"

int main() {
    std::map<prefix, std::vector<std::string>> statetab;  //  current statetab
    std::string filename;
    std::cin >> filename;
    fulfilStatetab(filename, &statetab);
    for (auto it = statetab.begin(); it != statetab.end(); ++it) {
        std::cout << "[ ";
        for (auto it1 : it->first) {
            std::cout << it1 << " ";
        }
        std::cout << " ]  <--> { ";
        for (auto it2 : it->second) {
            std::cout << it2 << " | ";
        }
        std::cout << " }" << std::endl;
    }
    return 0;
}
