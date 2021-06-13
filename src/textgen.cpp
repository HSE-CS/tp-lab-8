// Copyright Leonidek23 2021

#include "textgen.h"
#include <deque>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <ctime>

void AddTable(std::string path, std::map<prefix,
        std::vector<std::string>> *stateTable) {
    std::ifstream input(path);
    prefix prefixs;
    std::string bufer;

    for (int i = 0; i < NPREF; i++) {
        input >> bufer;
        if (!bufer.empty()) {
            prefixs.push_back(bufer);
        }
    }

    while (!input.eof()) {
        input >> bufer;
        if (!bufer.empty()) {
            int Exist = 0;
            for (auto &i : (*stateTable)[prefixs]) {
                if (i == bufer)
                    Exist = 1;
                break;
            }
            if (Exist == 0)
                (*stateTable)[prefixs].push_back(bufer);
            prefixs.pop_front();
            prefixs.push_back(bufer);
            bufer.clear();
        }
    }
}

std::string Text(std::map<prefix,
        std::vector<std::string>> *stateTable) {
    std::ofstream output("src/output.txt");
    std::srand(std::time(NULL));
    prefix nach;
    std::string bufer;
    nach.push_back("You");
    nach.push_back("think");
    int rnd = std::rand() % (*stateTable)[nach].size();
    int i = 1;
    while ((i < MAXGEN) && !((*stateTable)[nach].empty())) {
        auto x = (*stateTable)[nach];
        bufer += " " + (*stateTable)[nach][rnd];
        nach.push_back((*stateTable)[nach][rnd]);
        nach.pop_front();
        if (i % 7 == 0)
            bufer += "\n";
        i++;
        rnd = std::rand() % (*stateTable)[nach].size();
    }
    output << bufer;
    return bufer;
}
