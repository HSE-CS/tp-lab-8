// Copyright 2021 Vlad

#include "textgen.h"
#include <deque>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <ctime>

void createStateTable(std::string path, std::map<prefix, 
    std::vector<std::string>>* stateTable) {
    std::ifstream input(path);
    prefix prefixs;
    std::string buf;
    if (!input.is_open())
        return;

    for (int i = 0; i < NPREF; i++) {
        input >> buf;
        if (buf != "") {
            prefixs.push_back(buf);
        }
    }

    while (!input.eof()) {
        input >> buf;
        if (buf != "") {
            bool isExist = false;
                for (int i = 0; i < (*stateTable)[prefixs].size(); i++) {
                    if ((*stateTable)[prefixs][i] == buf)
                        isExist = true;
                    break;
                }
            if(!isExist)
                (*stateTable)[prefixs].push_back(buf);
            prefixs.pop_front();
            prefixs.push_back(buf);
            buf.clear();
        }
    }
}

std::string generateText(std::map<prefix, 
    std::vector<std::string>>* stateTable) {
    std::ofstream output("src/output.txt");
    std::srand(std::time(NULL));
    std::string buf;
    prefix start;
    start.push_back("I");
    start.push_back("LOOKED");
    int rnd = std::rand() % (*stateTable)[start].size();
    int i = 1;
    while ((i < MAXGEN) && !((*stateTable)[start].empty())) {
        auto x = (*stateTable)[start];
        buf += " " + (*stateTable)[start][rnd];
        start.push_back((*stateTable)[start][rnd]);
        start.pop_front();
        if (i % 7 == 0)
            buf += "\n";
        i++;
        rnd = std::rand() % (*stateTable)[start].size();
    }
    output << buf;
    return buf;
}
