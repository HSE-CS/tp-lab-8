// Copyright KarMashanova 2021

#include "textgen.h"

void AddTab(std::string f_input) {
    std::ifstream input(f_input);
    prefix pref;
    std::string str;
    while (!input.eof()) {
        while (pref.size() < NPREF) {
            input >> str;
            if (!(str == "")) {
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
}

void Generating(std::string f_output) {
    std::ofstream out(f_output);
    srand(time(0));
    std::map<prefix, std::vector<std::string>>::iterator i;
    i = statetab.begin();
    std::advance(i, rand() % statetab.size());
    prefix pref(i->first);
    for (auto j : i->first) {
        out << j << " ";
    }
    int WordCount = i->first.size();
    std::string str;
    int sum = 0;
    while ((statetab[pref].size() != 0) && (WordCount < MAXGEN)) {
        int k = std::rand() % statetab[pref].size();
        str = statetab[pref][k];
        out << str << " ";
        sum=sum+1;
        WordCount++;
        pref.push_back(str);
        pref.pop_front();
    }
}