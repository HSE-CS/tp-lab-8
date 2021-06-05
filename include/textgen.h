#ifndef TP_LAB_8_TEXTGEN_H
#define TP_LAB_8_TEXTGEN_H

#include <vector>
#include <map>

#include <iostream>
#include <deque>

typedef std::deque<std::string> prefix;

const int N_PREF = 2;
const int MAX_GEN = 1000;

class Markov_Model{
private:
    std::string source_file;
    std::map <prefix, std::vector <std::string> > state_tab;
    void WritePair(prefix current_prefix, std::string W3);

public:
    void AddElements(const std::string& source_file_name);
    void GenerateText();

};





#endif //TP_LAB_8_TEXTGEN_H
