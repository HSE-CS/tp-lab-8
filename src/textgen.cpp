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
            if (ch == ' ' || ch == '\t' || ch == '\n' ||
                ch == '\0' || ch == '\r') {
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
    std::map<prefix,
        std::vector<std::string>>::iterator it = statetab.begin();

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
            prefix::iterator iterator_pref_from_current
                = current_pref.begin();
            int count = 0;
            while (iterator_pref_from_table != pref_chek.end()) {
                if ((*iterator_pref_from_table) ==
                    *(iterator_pref_from_current)) {
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

void Generator::generate() {
    int num_words = pref_len;
    std::deque<std::string> current_pref = this->random_pref();
    for (auto word : current_pref)
        result += word + ' ';
    std::string current_word;
    while (num_words < this->words_num) {
        current_word = this->find_suf_for_pref(current_pref);
        if (current_word == "") {
            current_pref = this->random_pref();
            current_word = this->find_suf_for_pref(current_pref);
        }
        result += current_word;
        num_words++;
        current_word.pop_back();
        current_pref.pop_front();
        current_pref.push_back(current_word);
    }
};

std::string Generator::find_suf_for_pref(std::deque<std::string> pref) {
    std::map<prefix, std::vector<std::string>>::iterator it
        = statetab.begin();
    while (it != statetab.end()) {
        prefix pref_chek = it->first;
        std::deque<std::string>::iterator it_pref_from_table
            = pref_chek.begin();
        std::deque<std::string>::iterator it_pref_from_vect = pref.begin();
        int count = 0;
        while (it_pref_from_table != pref_chek.end()) {
            if ((*it_pref_from_table) == *(it_pref_from_vect)) {
                it_pref_from_table++;
                it_pref_from_vect++;
            } else {
                count++;
                break;
            }
        }
        if (count == 0) {
            std::vector<std::string> suf = it->second;
            std::string result = "";
            result += suf[rand() % suf.size()] + " ";
            return result;
        }
        it++;
    }
        
    std::string result = "";
    return result;
}

std::deque<std::string> Generator::random_pref() {
    std::map<prefix, std::vector<std::string>>::iterator it;
    int pos_start = rand() % size;
    int count = 0;
    it = statetab.begin();
    while (count != pos_start && it != statetab.end()) {
        count++;
        it++;
    }

    prefix pref_chek = it->first;
    std::deque<std::string>::iterator it_pr = pref_chek.begin();
    std::deque<std::string> result;
    for (auto word : pref_chek) {
        result.push_back(word);
    }
    return result;
}

std::string Generator::getResult() {
    return result;
};

MarckovChair::MarckovChair(std::vector<std::string> words,
    int pref_len, int num_words) {
    Linker linker_for_chair(pref_len, words);
    Generator generator_for_chair(pref_len, num_words,
        linker_for_chair.getTable());
    this->result = generator_for_chair.getResult();
}
MarckovChair::MarckovChair(const char* link, int pref_len, int num_words) {
    TextParser parser_for_chair(link);
    Linker linker_for_chair(pref_len, parser_for_chair.GetWords());
    Generator generator_for_chair(pref_len, num_words,
        linker_for_chair.getTable());
    this->result = generator_for_chair.getResult();
}

std::string MarckovChair::getResult() {
    return result;
}
