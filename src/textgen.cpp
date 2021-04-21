// Copyright 2021 valvarl

#include <fstream>
#include <algorithm>
#include <random>
#include "textgen.h"

std::string &removeSpecialCharacter(std::string &s) {
    for (int i = 0; i < s.size(); i++) {
        // Finding the character whose
        // ASCII value fall under this
        // range
        if (s[i] < 'A' || s[i] > 'Z' && s[i] < 'a' || s[i] > 'z')
        {
            // erase function to erase
            // the character
            s.erase(i, 1);
            i--;
        }
    }
    std::transform(s.begin(), s.end(), s.begin(), tolower);
    return s;
}

void preprocess_table(const std::string& filename) {
    std::string s;  // сюда будем класть считанные строки
    std::ifstream file(filename);  // файл из которого читаем
    std::string delim = " ";
    static std::string word;
    std::deque<std::string> words;


    while(getline(file, s)) {  // пока не достигнут конец файла класть очередную строку в переменную (s)
        if (!s.empty() and s.at(0) != '#') {
            s += '\n';
            auto start = 0U;
            auto end = s.find(delim);
            while (end != std::string::npos)
            {
                word = s.substr(start, end - start);
                words.push_back(removeSpecialCharacter(word));
                start = end + delim.length();
                end = s.find(delim, start);
            }

            word = s.substr(start, end);
            words.push_back(removeSpecialCharacter(word)+'\n');
        } else {
            static prefix p{};
            if (words.size() > NPREF) {
                for (int i = 0; i < NPREF; i++) {
                    p.push_back(words.front());
                    words.pop_front();
                }

                while (!words.empty()) {
                    static std::vector<std::string> v{words.front()};
                    if ( statetab.find(p) == statetab.end() ) {
                        statetab[p] = v;
                    } else {
                        statetab[p].insert(std::end(statetab[p]),
                                           std::begin(v), std::end(v));
                    }
                    p.pop_front();
                    p.push_back(words.front());
                    words.pop_front();
                }
            }
            words.clear();
        }
    }

    file.close();
}

std::string generate(prefix &starting) {
    std::string text;
    std::minstd_rand simple_rand;
//    simple_rand.seed(
//    std::chrono::system_clock::now().time_since_epoch().count());
    simple_rand.seed(42);
    while (text.size() < MAXGEN) {
        text += starting.front() + ' ';
        starting.push_back(
                statetab[starting][simple_rand() % statetab[starting].size()]);
        starting.pop_front();
    }
    return text;
}
