// Copyright 2021 MalininDmitry

#include "textgen.h"

std::vector<std::string> splitBySpaces(std::string txt) {
    std::istringstream iss(txt);
    std::vector<std::string> tokens;
    std::copy(std::istream_iterator<std::string>(iss),
              std::istream_iterator<std::string>(),
              std::back_inserter<std::vector<std::string>>
              (tokens));
    return tokens;
}

std::map<std::deque<std::string>, std::vector<std::string>> createPrefix(std::string path) {
    std::string line;
    std::ifstream in(path);
    std::map<std::deque<std::string>, std::vector<std::string>>
    statetab;
    if (in.is_open()) {
        while (getline(in, line)) {
            if (line != "") {
                std::string text = line;
                removeUnnecessaryCharacter(text);
                std::vector<std::string> sepText =
                splitBySpaces(text);
                std::deque<std::string> prefix;
                for (int i = 0; i < sepText.size()-NPREF; i++) {
                    for (int j = 0; j < NPREF; j++) {
                        prefix.push_back(sepText[i+j]);
                    }
                    if (statetab.find(prefix) == statetab.end() ) {
                        std::vector<std::string> nw;
                        nw.push_back(sepText[i+NPREF]);
                        statetab.insert(
                        std::pair<std::deque<std::string>, std::vector<std::string>>
                                        (prefix, nw));
                    } else {
                        statetab[prefix].push_back
                        (sepText[i+NPREF]);
                    }
                    for (int j = 0; j < NPREF; j++) {
                        prefix.pop_front();
                    }
                }
            }
        }
        in.close();
    } else {
        std::cout << "close" << std::endl;
    }
    return statetab;
}

void removeUnnecessaryCharacter(std::string &text) {
    for (int i = 0; i < text.size(); i++) {
        if ((text[i] < 'A' || text[i] > 'Z')
            && (text[i] < 'a' || text[i] > 'z') && (text[i] != ' ')) {
            text.erase(i, 1);
            i--;
        }
    }
    return;
}

void generateText(std::string path,
                  std::map<std::deque<std::string>,
                  std::vector<std::string>> &statetab) {
    std::ofstream out;          
    out.open(path);
    std::random_device rd;
    std::mt19937 mersenne(rd());
    std::vector<std::deque<std::string>> k;
    std::deque<std::string> firs;
    int count = 0;
    for (auto const& key: statetab) {
        for (int i = 0; i < NPREF; i++) {
            firs.push_back(key.first[i]);
            out << firs[i] << " ";
            count += firs[i].length();
        }
        break;
    }
    int g = 0;
    if (out.is_open()){
        while ((count < MAXGEN) &&
               (statetab.find(firs) != statetab.end())) {
            g = mersenne() % statetab[firs].size();
            out << statetab[firs].at(g) << " ";
            count += statetab[firs].at(g).length();
            firs.push_back(statetab[firs].at(g));
            firs.pop_front();
        }
    }
}
