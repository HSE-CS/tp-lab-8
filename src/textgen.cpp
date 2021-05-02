#include "textgen.h"

void MarkovChain::MakeTable(std::string file_) {
    prefix pref;
    std::string str;
    std::ifstream input(file_);
    while (!input.eof()) {
        while (pref.size() < NPREF) {
            input >> str;
            if (str != "") {
                pref.push_back(str);
            }
            else {
                break;
            }
        }
        input >> str;
        if (str == "") { break; }
        statetab[pref].push_back(str);
        pref.push_back(str);
        pref.pop_front();
        str="";
    }
    input.close();
}

std::string MarkovChain::CreateNewText() {
    std::srand(std::time(0));
    std::string res;
    std::map<prefix, std::vector<std::string>>::iterator it;
    it = statetab.begin();
    size_t a = std::rand() % statetab.size();
    std::advance(it, a);
    prefix pref(it->first);
    for (auto i : it->first) {
        res += i + " ";
    }
    int word_num = it->first.size();
    std::string str;
    while (statetab[pref].size() != 0 && word_num < MAXGEN) {
        int j = std::rand() % statetab[pref].size();
        str = statetab[pref][j];
        res += str + " ";
        pref.push_back(str);
        pref.pop_front();
        word_num++;
    }
    return res;
}

int MarkovChain::MakeTableInt(std::string file_) {
    prefix pref;
    std::string str;
    std::ifstream input(file_);
    while (!input.eof()) {
        while (pref.size() < NPREF) {
            input >> str;
            if (str != "") {
                pref.push_back(str);
            }
            else {
                break;
            }
        }
        input >> str;
        if (str == "") { break; }
        statetab[pref].push_back(str);
        pref.push_back(str);
        pref.pop_front();
        str = "";
    }
    input.close();
    return pref.size();
}