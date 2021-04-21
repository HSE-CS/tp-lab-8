// Copyright 2021 valvarl

#include <iostream>
#include "textgen.h"

int main(int argc, char* argv[]) {
    preprocess_table("BonesLyricsClean.txt");
    //prefix st{"those", "see"};
    //std::vector<std::string> v{"123"};
    //statetab[st] = v;
    prefix stt{"those", "see"};
    if ( statetab.find(stt) == statetab.end() ) {
        std::cout << "no";
    }
    //std::cout << generate(st);
}