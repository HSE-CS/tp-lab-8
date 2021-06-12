// Copyright 02.05.21 Lavrov Artyom

#include "textgen.h"

void TextGen::setPath(std::string from) {
    this->path = from;
}

void TextGen::ReadText() {
    std::ifstream file;
    file.open(getPath());
    if (file.is_open()) {
        std::cout << "open" << std::endl;
        std::string str = "";
        while (!file.eof()) {
            this->wordcount++;
            file >> str;
            text.push_back(str);
        }
    } else {
        std::cout << "such file was not found" << std::endl;
    }
    file.close();
}

std::string TextGen::getPath() {
    return this->path;
}

int TextGen::getCount() {
    return this->wordcount;
}

void TextGen::printText() {
    for (int i = 0; i < getCount(); i++) {
        std::cout << text[i] << " ";
    }
}

void TextGen::makePairs() {
    prefix pre;
    int i = 0;
    while (i < getCount() - 1) {
        while (pre.size() < NPREF) {
            pre.push_back(text[i]);
            i++;
            if (i == NPREF) i = NPREF - 1;
        }
        i++;
        statetab[pre].push_back(text[i]);
        pre.push_back(text[i]);
        pre.pop_front();
        if (i == getCount() - 1) statetab[pre].push_back("THE END");
    }
}

std::string TextGen::createText(int words) {
    std::srand(std::time(NULL));
    std::string str, newText = "";
    std::map<prefix, std::vector<std::string>>::iterator
        iter = statetab.begin();
    newText = text[0] + " " + text[1] + " " + text[2] + " ";
    for (std::string str2 : iter->first) {
        newText += str2 + " ";
    }
    prefix pre(iter->first);
    int usedWords = iter->first.size() + 3;
    while (statetab[pre].size() != 0 && (usedWords < MAXGEN && usedWords < words)) {
        str = statetab[pre][std::rand() % statetab[pre].size()];
        newText += str + " ";
        pre.push_back(str);
        pre.pop_front();
        usedWords++;
    }
    return newText;
}