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
         Parsing();
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
        Link();
    }
    void Link();
    std::map<prefix, std::vector<std::string>> getTable();
};

class Generator {
    int pref_len = 1;
    std::map<prefix, std::vector<std::string>> statetab;
    int words_num = 2;
    std::string result = "";
    int size;

public:
    explicit Generator(int len, int words_num, std::map<prefix, std::vector<std::string>> statetab) {
        pref_len = len;
        this->words_num = words_num;
        this->statetab = statetab;
        this->size = statetab.size();
        generate();
    }
    std::deque<std::string> random_pref();
    std::string find_suf_for_pref(std::deque<std::string>);
    void generate();
    std::string getResult();
};

class MarckovChair {
private:
    std::string result;
public:
    explicit MarckovChair(std::vector<std::string>, int, int);
    explicit MarckovChair(const char*, int, int);
    std::string getResult();
};

#endif  // INCLUDE_TEXTGEN_H_
