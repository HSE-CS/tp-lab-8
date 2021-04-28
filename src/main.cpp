#include <fstream>
#include <deque>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <list>
#include <iterator>
#include "textgen.h"






std::string pref_by_suf(std::string a, std::map<prefix, std::vector<std::string>> st) {
    if (a == "") {
        std::map<prefix, std::vector<std::string>>::iterator it = st.begin();
        it = st.begin();
        int count = 0;
        for (it; it != st.end(); it++) {
            count++;
        }

        int pos_start = rand() % count;
        count = 0;
        it = st.begin();
        while (count != pos_start && it != st.end()) {
            count++;
            it++;
        }

        prefix pref_chek = it->first;
        std::deque<std::string>::iterator it_pr = pref_chek.begin();
        std::string result = "";
        for (auto word : pref_chek) {
            result += word + ' ';
        }
        return result;
    }
    else {
        std::map<prefix, std::vector<std::string>>::iterator it = st.begin();
        prefix pref_chek = it->first;
        std::deque<std::string>::iterator it_pr = pref_chek.begin();
        int count = 0;
        int flag = 0;
        while (it != st.end()) {
            while (it_pr != pref_chek.end()) {
                if ((*it_pr) == a) {
                    count++;
                }
                it_pr++;
            }
            if (count == pref_chek.size()) {
                flag = 1;
                break;
            };
            it++;
        }
        if (flag) {
            std::vector<std::string> suf = it->second;
            std::vector<std::string>::iterator it_pr = suf.begin();
            std::string result = "";
            result += suf[rand() % suf.size()] + " ";
            return result;
        }
        if (!flag) {
            std::map<prefix, std::vector<std::string>>::iterator it = st.begin();
            it = st.begin();
            int count = 0;
            for (it; it != st.end(); it++) {
                count++;
            }

            int pos_start = rand() % count;
            count = 0;
            it = st.begin();
            while (count != pos_start && it != st.end()) {
                count++;
                it++;
            }

            prefix pref_chek = it->first;
            std::deque<std::string>::iterator it_pr = pref_chek.begin();
            std::string result = "";
            for (auto word : pref_chek) {
                result += word + ' ';
            }
            return result;
        }
    }
}


int main() {
    const char* link = "text.txt";
    TextParser demo(link);
    demo.Parsing();
    std::vector<std::string> words = demo.GetWords();
    std::vector<std::string> wordx;
    Linker demo_Linker(6, words);
    demo_Linker.Link();
    std::map<prefix, std::vector<std::string>> statetab = demo_Linker.getTable();
    const int MAXGEN = 20; //объем текста на выходе
    std::map<prefix, std::vector<std::string>>::iterator it = statetab.begin();
    it = statetab.begin();
    int count = 0;
    for (it; it != statetab.end(); it++) {
        count++;
    }
    
    int pos_start = rand() % count;
    count = 0;
    it = statetab.begin();
    while (count != pos_start && it != statetab.end()) {
        count++;
        it++;
    }

    std::string result = "";
    std::string current_word = "";
    prefix pref_chek = it->first;
    std::deque<std::string>::iterator it_pr = pref_chek.begin();
    for (auto pref_word : pref_chek) {
        result += pref_word;
        current_word = result;
    }

    int num_word = 1;
    while (num_word < MAXGEN) {
        current_word = pref_by_suf(current_word, statetab);
        result += current_word;
        num_word++;
    }

    std::cout << result;
    return 0;
}

