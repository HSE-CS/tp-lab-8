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
    void WritePair(const prefix& current_prefix, const std::string& W3);

public:
    std::map <prefix, std::vector <std::string> > state_tab;
    void AddElements(const std::string& source_file_name);
    std::string GenerateText();
    std::string GenerateText(prefix start);

};





#endif //TP_LAB_8_TEXTGEN_H
