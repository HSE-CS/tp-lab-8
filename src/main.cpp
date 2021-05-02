// Copyright 2021 Bogomazov Mikhail
#include "../include/textgen.h";

int main() {
    GenerationOfText genText;
    std::string text = genText.readFromFile("inp.txt");
    genText.genTable(text);
    std::string answer = genText.genText();
    genText.writeToFile(answer);
    return 0;
}
