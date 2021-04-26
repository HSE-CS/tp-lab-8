//  Copyright 2021 Nikita Naumov
#include "../include/textgen.h"

void fulfilStatetab(std::string fileName, 
                    std::map<prefix, std::vector<std::string>>* statetab) {
    std::ifstream inputFile(fileName);
    prefix prefixVar;
    std::string str;
    while (!inputFile.eof()) {
        if (prefixVar.empty()) {
            for (size_t i = 0; i < NPREF; ++i) {
                inputFile >> str;
                prefixVar.push_back(str);
                str.clear();
            }
            inputFile >> str;
            (*statetab)[prefixVar].push_back(str);
            prefixVar.pop_front();
            prefixVar.push_back(str);
            str.clear();
        } else {
                inputFile >> str;
                (*statetab)[prefixVar].push_back(str);
                prefixVar.pop_front();
                prefixVar.push_back(str);
                str.clear();
        }
    }
    inputFile.close();
}

std::string generateText(std::map<prefix, std::vector<std::string>>* statetab,
                        prefix start) {
    std::string s;

    return s;
}
