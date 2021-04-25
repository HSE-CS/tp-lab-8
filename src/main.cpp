#include <fstream>
#include <deque>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <list>
#include <iterator>


typedef std::deque<std::string> prefix;



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
    const int NPREF = 1; // количество слов в префиксе
    const int MAXGEN = 20; //объем текста на выходе
    std::map<prefix, std::vector<std::string>> statetab; // префикс-суффиксы

    std::list< std::map<prefix, std::vector<std::string>>> prefix_list;
    const char* link = "text.txt";

    std::ifstream in;
    in.open(link, std::ios::in);

    std::vector<std::string> words;
    std::string* word = new std::string;
    char ch;
    if (!in) {
        std::cout << "I can't open file!";
        return 1;
    }
    while (in) {
        in.get(ch);
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0' || ch == '\r') {
            if (word->size() == 0) {
                continue;
            } 
            else {
                std::string word_a = *word;
                word_a += '\0';
                words.push_back(word_a);
                word->clear();
                word->resize(0);
            }
        } else {
            *word += ch;
        }
    }
    
    in.close();

    prefix m_pref; 
    std::vector<std::string> suf;
    std::map<prefix, std::vector<std::string>>::iterator it = statetab.begin();

    size_t num_words = words.size();
    for (auto current_word : words) {
        if (m_pref.empty()) {
            m_pref.push_back(current_word);
            continue;
        }

        it = statetab.begin();
        int flag = 0;
        while (it != statetab.end()) {
            prefix pref_chek = it->first;
            std::deque<std::string>::iterator it_pr = pref_chek.begin();
            std::deque<std::string>::iterator it_pr_n = m_pref.begin();
            int count = 0;
            while (it_pr != pref_chek.end()) {
                if ((*it_pr) == *(it_pr_n)) {
                    count++;
                }
                it_pr++;
                it_pr_n++;
            }
            if (count == pref_chek.size()) {
                it->second.push_back(current_word);
                flag = 1;
                break;
            };
            it++;
        }
        if (flag == 0) {
            suf.push_back(current_word);
            statetab[m_pref] = suf;
            suf.clear();
            m_pref.clear();
            m_pref.push_back(current_word);
        }
    }

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

