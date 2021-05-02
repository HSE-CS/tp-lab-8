// Copyright Kasyanov 2021
#include "../include/textgen.h"

std::vector<std::string> createWordVector(std::string file) {
    std::ifstream f(file);
    std::string str;
    std::vector<std::string> vec_word;
    while(f >> str) {
       if (!str.empty()) {
           str = (std::ispunct(str[str.size() - 1]) == 0) ? str : str.substr(0, str.size() - 1);
           vec_word.push_back(str);
       }
   }
   f.close();
   return vec_word;
}

std::map<prefix, std::vector<std::string>> createTable(std::vector<std::string> vec_word) {
    prefix prfx;
    std::map<prefix, std::vector<std::string>> table;
    prfx.push_back(vec_word[0]);
    for (int i = 1; i < vec_word.size() - 1; ++i) {
        prfx.push_back(vec_word[i]);
        table[prfx].push_back(vec_word[i + 1]);
        prfx.pop_front();
    }
    return table;
}

std::string generateText(std::map<prefix, std::vector<std::string>> table) {
    auto curr_deque = table.begin()->first;
    auto w1 = curr_deque.front();
    auto w2 = curr_deque.back();
    std::string gen;
    int i = 1;
    while (i < MAXGEN) {
        if (i % 3) {
            gen += (w1 + ' ');
        } else {
            gen += (w1 + '\n');
        }
        ++i;
        if (table[curr_deque].empty()) {
            gen += (w2 + '.');
            break;
        }
        int random_index = rand() % table[curr_deque].size();
        auto w3 = table[curr_deque][random_index];
        w1 = w2;
        w2 = w3;
        curr_deque.pop_front();
        curr_deque.push_back(w3);
    }
    return gen;
}
