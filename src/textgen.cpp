

#include <fstream>
#include <random>
#include <ctime>

#include "textgen.h"

using namespace std;

void Markov_Model::AddElements(const string& source_file_name) {

    this->source_file = source_file_name;

    fstream source;
    source.open(source_file_name);
    if(!source.is_open()){
        cout << "Cannot open the file";
        return;
    }

    string words[N_PREF];
    prefix current_prefix;

    for(auto i:words){
        if(!source.eof()) {
            source >> i;
            current_prefix.push_back(i);
        } else{
            cout << "Too short file!" << endl;
            source.close();
            return;
        }
    }

    while(!source.eof()){
        string W3;
        source >> W3;

        WritePair(current_prefix, W3);

        current_prefix.pop_front();
        current_prefix.push_back(W3);

    }

    source.close();
}

void Markov_Model::WritePair(const prefix& current_prefix, const string& W3){

    vector <string> suffix;

    if(this->state_tab.find(current_prefix) == state_tab.end()){
        suffix.push_back(W3);
        this->state_tab.insert({current_prefix, suffix});
    } else {
        suffix = state_tab[current_prefix];
        suffix.push_back(W3);
        state_tab[current_prefix] = suffix;
    }

}


string Markov_Model::GenerateText() {

    string result;

    string words[N_PREF];
    prefix current_prefix;

    fstream source;
    source.open(this->source_file);
    if(!source.is_open()){
        cout << "Cannot open the source file!" << endl;
        return result;
    }
    for(auto i:words){
        if(!source.eof()) {
            source >> i;
            current_prefix.push_back(i);
        } else{
            cout << "Too short file!" << endl;
            source.close();
            return result;
        }
    }
    source.close();

    result = this->GenerateText(current_prefix);
    return result;

}

string Markov_Model::GenerateText(prefix current_prefix){
    string result;
    for(auto const &words : current_prefix){
        result.append(words);
        result.append(" ");

    }

    for(int i = 0; i < MAX_GEN; i++){

        if(this->state_tab.find(current_prefix) == this->state_tab.end()){
            return result;
        }

        vector<string> suffix = this->state_tab[current_prefix];
        size_t size = suffix.size();

        srand(time(NULL));
        unsigned int index = rand() % size;

        string W3 = suffix[index];

        result.append(W3);
        result.append(" ");

        current_prefix.pop_front();
        current_prefix.push_back(W3);
    }

    return result;
}