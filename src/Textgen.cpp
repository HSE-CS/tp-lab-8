//  Copyright Baklanov 2021
#include "Textgen.h"
#include <fstream>
#include <iostream>
#include <string>

std::string getLastWord(std::string str) {
    int i = str.length() - 1;
    while(str[i] != ' ') {
        --i;
    }
    int size = str.length() - i - 1;
    std::string lastWord = str.substr(i + 1, str.length() - i);
    return lastWord;
}

void cutEnd(std::string* a) {
    if (((*a)[(*a).length() - 1] > 'z') &&
        ((*a)[(*a).length() - 1] < 'a')) {
        (*a).erase((*a).length() - 1);
    }
}

std::map<prefix, std::vector<std::string> >
makeStatetab(const int NPREF,
    const int MAXGEN,
    std::string filepath) {
    std::map<prefix, std::vector<std::string> > statetab;
    std::string buf;
    std::ifstream fin(filepath);
    prefix bufPref;
    std::vector<std::string> bufSuf;
    /*while (!fin.eof()) {
        fin >> buf;
        if ((buf[buf.length() - 1] > 'z') &&
            (buf[buf.length() - 1] < 'a')) {
            cutEnd(&buf);
        }
        bufSuf.push_back(buf);
    }
    for (std::string a : bufSuf) {
        std::cout << a << std::endl;
    }
    
    while(!fin.eof()) {
        for (int i = 0; i < NPREF; ++i) {
            bufPref.push_back(bufSuf[std::rand() % bufSuf.size()]);
        }
        std::string suffix;*/
    for (int i = 0; i < NPREF; ++i) {
        fin >> buf;
        cutEnd(&buf);
        bufPref.push_back(buf);
    }
    while (!fin.eof()) {
        auto it = statetab.find(bufPref);
        if (it != statetab.end()) {
            fin >> buf;
            cutEnd(&buf);
            it->second.push_back(buf);
        }
        else {
            fin >> buf;
            cutEnd(&buf);
            std::vector<std::string> newSuff;
            newSuff.push_back(buf);
            statetab.emplace(bufPref, newSuff);
        }
        bufPref.push_back(buf);
        bufPref.erase(bufPref.begin());

    }
    fin.close();
    return statetab;
}

std::string generateText(std::map<prefix,
    std::vector<std::string> >* statetab,
    prefix* startPref) {
    std::string genText;
    auto it = statetab->find(*startPref);
    if (it != statetab->end()) {
        genText = it->second[std::rand() % it->second.size()];
    }
    return genText;
}


