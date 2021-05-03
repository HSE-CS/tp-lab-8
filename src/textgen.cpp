//  Copyright 2021 kisozinov

#include "textgen.h"

void fillStatetab(std::map<prefix, std::vector<std::string>>* statetab,
                    std::string fileName) {
    std::ifstream inputFile(fileName);
    prefix prefixArr;
    std::string buffer;
    while (!inputFile.eof()) {
        if (prefixArr.empty()) {
            for (size_t i = 0; i < NPREF; ++i) {
                inputFile >> buffer;
                prefixArr.push_back(buffer);
                buffer.clear();
            }
            inputFile >> buffer;
            (*statetab)[prefixArr].push_back(buffer);
            prefixArr.pop_front();
            prefixArr.push_back(buffer);
            buffer.clear();
        } else {
            inputFile >> buffer;
            bool isSubstr = false;
            for (size_t i = 0; i < (*statetab)[prefixArr].size(); ++i) {
                if ((*statetab)[prefixArr][i] == buffer) {
                    isSubstr = true;
                    break;
                }
            }
            if (!isSubstr) {
                (*statetab)[prefixArr].push_back(buffer);
            }
            prefixArr.pop_front();
            prefixArr.push_back(buffer);
            buffer.clear();
        }
    }
    inputFile.close();
}

void printMap(std::map<prefix, std::vector<std::string>>* statetab) {
        for (auto pr = (*statetab).begin(); pr != (*statetab).end(); ++pr) {
        std::cout << "[ ";
        for (auto it1 : pr->first) {
            std::cout << it1 << " ";
        }
        std::cout << " ] --- < ";
        for (auto it2 : pr->second) {
            std::cout << it2;
        }
        std::cout << " >" << std::endl;
    }
}

std::string generateText(std::map<prefix, std::vector<std::string>>* statetab,
                        prefix& start) {
    std::string buffer;
    unsigned cnt = NPREF;
    while ((cnt <= MAXGEN) && (!((*statetab)[start].empty()))) {
        if (buffer.empty()) {
            for (auto pref = start.begin(); pref != start.end(); ++pref) {
                if (pref != start.end() - 1) {
                    buffer += *pref + " ";
                } else {
                    buffer += *pref;
                }
            }
        }
        unsigned curRand = std::rand()%(*statetab)[start].size();
        buffer += " " + (*statetab)[start][curRand];
        start.push_back((*statetab)[start][curRand]);
        start.pop_front();
        if (!(cnt%5) && cnt) {
            buffer += "\n";
        }
        cnt++;
    }
    return buffer;
}
