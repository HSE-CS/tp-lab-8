// Copyright 2021 Soda

#ifndef INCLUDE_TEXTGEN_H_
#define INCLUDE_TEXTGEN_H_

#include <string>
#include <vector>
#include <map>
#include <deque>
#include <iterator>

typedef std::deque<std::string> prefix;

class TextParser {
 private:
     std::vector<std::string> words;
     const char* file = nullptr;
 public:
     explicit TextParser(const char* file_name) {
         file = file_name;
     }
     void Parsing();
     std::vector<std::string> GetWords();
};


class Linker {
    std::vector<std::string> words;
    int pref_len = 1;
    std::map<prefix, std::vector<std::string>> statetab;

public:
    explicit Linker(int len, std::vector<std::string> words) {
        pref_len = len;
        this->words = words;
    }
    void Link();
    std::map<prefix, std::vector<std::string>> getTable();
};



#endif  // INCLUDE_TIMEDDOOR_H_
