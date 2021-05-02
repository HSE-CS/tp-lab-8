// Copyright 2021 Bogomazov Mikhail
#include <stdlib.h>
#include <ctime>
#include "../include/textgen.h"

void GenerationOfText::genTable(std::string text) {
    int i = 0, state = 0, count = -1;
    while (text[i] != '\0') {
        if (state == 0 && text[i] != ' '
            && text[i] != '\r' && text[i] != '\n') {
            state = 1;
            count++;
            words.push_back("");
            words[count] = words[count] + text[i];
        } else if (state == 1 &&
            (text[i] == ' ' || text[i] == '\r' || text[i] == '\n')) {
            state = 0;
        } else if (state == 1 && text[i] != ' '
            && text[i] != '\r' && text[i] != '\n') {
            words[count] = words[count] + text[i];
        }
        i++;
    }
    for (int i = 0; i < words.size() - NPREF + 1; i++) {
        prefix prf;
        for (int j = 0; j < NPREF; j++)
            prf.push_back(words[i + j]);
        if (i + NPREF < words.size()) {
            stateTab[prf].push_back(words[i + NPREF]);
        } else {
            stateTab[prf].push_back("END_OF_FILE");
        }
    }
}

std::string GenerationOfText::genText() {
    prefix str;
    for (int i = 0; i < NPREF; i++)
        str.push_back(words[i]);
    std::string result = "";
    int count = 1;
    while (result.size() < MAXGEN) {
        if (result.size() == 0) {
            for (int i = 0; i < NPREF; i++)
                result = result + str[i] + ' ';
        }
        int ran_;
        if (stateTab[str].size() == 1 && stateTab[str][0] == "END_OF_FILE")
            break;
        if (stateTab[str].size() == 0)
            break;
        unsigned int seed = time(NULL);
        ran_ = rand_r(&seed) % stateTab[str].size();
        if (stateTab[str][stateTab[str].size() - 1] == "END_OF_FILE")
            ran_ = rand_r(&seed) % (stateTab[str].size() - 1);
        result = result + stateTab[str][ran_] + ' ';
        if (count * 100 - result.size() < 0
            || count * 100 - result.size() > 100) {
            count++;
            result = result + '\n';
        }
        std::string tmp = stateTab[str][ran_];
        for (int i = 0; i < NPREF - 1; i++) str[i] = str[i + 1];
        str[NPREF - 1] = tmp;
    }
    return result;
}
std::string GenerationOfText::readFromFile(std::string filename) {
    std::string world;
    std::string text = "";
    std::ifstream OriginText(filename);
    if (OriginText.is_open()) {
        while (!OriginText.eof()) {
            OriginText >> world;
            text = text + world + ' ';
        }
    }
    OriginText.close();
    return text;
}

void GenerationOfText::writeToFile(std::string answer) {
    std::ofstream out;
    out.open("output.txt");
    if (out.is_open()) {
        out << answer;
    }
    out.close();
}

GenerationOfText::GenerationOfText() {
    this->words;
    this->stateTab;
}

GenerationOfText::GenerationOfText(
    std::map<prefix, std::vector<std::string>> val,
    std::vector<std::string> word) {
    stateTab = val;
    words = word;
}
