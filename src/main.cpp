// Copyright 2021 DBarinov
#include "textgen.h"

int main() {
    TextGenerator test;
    std::string text = test.fileInput("xxxtentacion.txt");
    test.CreateTable(text);
    std::string output = test.newText();
    test.fileOutput(output);
    return 0;
}
