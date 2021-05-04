// Copyright 2021 SoDa

#include "textgen.h"
#include <iostream>

int main() {
    setlocale(LC_ALL, "russian");
    const char* link = "text.txt";
    MarckovChair demo(link, 1, 500);
    std::string result = demo.getResult();
    std::cout << result;
    demo.popResult();
    return 0;
}
