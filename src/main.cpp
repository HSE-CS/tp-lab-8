// Copyright 2021 SoDa

#include "textgen.h"
#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");
    const char* link = "text.txt";
    MarckovChair demo(link, 10, 200);
    std::string result = demo.getResult();
    std::cout << result;
    return 0;
}
