// Copyright 2021 GN
#include "textgen.h"

int main() {
    MarkovChain ex1;
    ex1.MakeTable("text.txt");
    std::string res = ex1.CreateNewText();
    std::cout << res;
    std::cout << ex1.MakeTableInt("text.txt") << std::endl;
    return 0;
}