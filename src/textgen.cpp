// Copyright 2021 SoDa

#include "textgen.h"
#include <fstream>

#include <iostream>
void TextParser::Parsing() {
    if (file) {
        std::ifstream in;
        in.open(this->file, std::ios::in);
        std::string* word = new std::string;
        char ch;
        if (!in) {
            throw("I can't open file!");
        }
        while (in) {
            in.get(ch);
            if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0' || ch == '\r') {
                if (word->size() == 0) {
                    continue;
                } else {
                    std::string word_a = *word;
                    word_a += '\0';
                    this->words.push_back(word_a);
                    word->clear();
                    word->resize(0);
                }
            } else {
                *word += ch;
            }
        }
        in.close();
    } else {
        throw("Please input correct file!");
    }
}

std::vector<std::string> TextParser::GetWords() {
	return words;
}

void Linker::Link() {
    prefix current_pref;
    std::vector<std::string> new_suf;
    std::map<prefix, std::vector<std::string>>::iterator it = statetab.begin();

    size_t num_words = words.size();
    for (auto current_word : words) {
        if (current_pref.empty() || current_pref.size() < this->pref_len) {
            current_pref.push_back(current_word);
            continue;
        }

        it = statetab.begin();
        int flag = 0;
        while (it != statetab.end()) {
            prefix pref_chek = it->first;
            prefix::iterator iterator_pref_from_table = pref_chek.begin();
            prefix::iterator iterator_pref_from_current = current_pref.begin();
            int count = 0;
            while (iterator_pref_from_table != pref_chek.end()) {
                if ((*iterator_pref_from_table) == *(iterator_pref_from_current)) {
                    iterator_pref_from_table++;
                    iterator_pref_from_current++;
                } else {
                    count++;
                    break;
                }
            }
            if (count == 0) {
                it->second.push_back(current_word);
                flag = 1;
                current_pref.pop_front();
                current_pref.push_back(current_word);
                break;
            };
            it++;
        }
        if (flag == 0) {
            new_suf.push_back(current_word);
            statetab[current_pref] = new_suf;
            new_suf.clear();
            current_pref.pop_front();
            current_pref.push_back(current_word);
        }
    }
}

std::map<prefix, std::vector<std::string>> Linker::getTable() {
    return statetab;
}