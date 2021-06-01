// Copyright dash 2021

#include "textgen.h"

void AddingToTab(std::string f_input) {
    std::ifstream input(f_input);
    prefix pref;
    std::string s;
    while (!input.eof()) {
        while (pref.size() < NPREF) {
            input >> s;
            if (s == "") {
                break;
            }
            else {
                pref.push_back(s);
            }
        }

        input >> s;

        if (s == "") { break; }
        statetab[pref].push_back(s);
        pref.push_back(s);
        pref.pop_front();
        s = "";
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
    std::string s;
    int sum = 0;
    while ((statetab[pref].size() != 0) && (WordCount < MAXGEN)) {
        int k = std::rand() % statetab[pref].size();
        s = statetab[pref][k];
        out << s << " ";
        sum++;
        WordCount++;
        pref.push_back(s);
        pref.pop_front();
    }
}