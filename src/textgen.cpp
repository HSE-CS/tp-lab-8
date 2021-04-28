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
                bool substrExists = false;
                for (size_t i = 0; i < (*statetab)[prefixVar].size(); ++i) {
                    if ((*statetab)[prefixVar][i] == str) {
                        substrExists = true;
                        break;
                    }
                }
                if (!substrExists) {
                    (*statetab)[prefixVar].push_back(str);
                }
                prefixVar.pop_front();
                prefixVar.push_back(str);
                str.clear();
        }
    }
    inputFile.close();
}

std::string generateText(std::map<prefix, std::vector<std::string>>* statetab,
                        prefix& start) {
    std::string str;
    unsigned count = NPREF;
    while ((count <= MAXGEN) && (!((*statetab)[start].empty()))) {
        if (str.empty()) {
            for (auto it = start.begin(); it != start.end(); ++it) {
                if (it != start.end() - 1) {
                    str += *it + " ";
                } else {
                    str += *it;
                }
            }
        }
        unsigned curRand = std::rand()%(*statetab)[start].size();
        str += " " + (*statetab)[start][curRand];
        start.push_back((*statetab)[start][curRand]);
        start.pop_front();
        if (!(count%7) && count) {
            str += "\n";
        }
        ++count;
    }
    return str;
}

void printMap(std::map<prefix, std::vector<std::string>>* statetab) {
        for (auto it = (*statetab).begin(); it != (*statetab).end(); ++it) {
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
}
