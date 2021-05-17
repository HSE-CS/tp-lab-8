// Copyright 2021 Vadukk

#include "textgen.h"

int main() {
    GenerationOfText test;
    std::string text = test.ReadFromFile("Russia.txt");
    test.MakingTheTable(text);
    std::string answer = test.GenerationNewText();
    test.WritingToFile(answer);
    return 0;
}