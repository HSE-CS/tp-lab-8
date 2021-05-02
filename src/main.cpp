// Copyright Kasyanov 2021

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>
#include <ctime>
#include "textgen.cpp"

int main() {
    srand(time(0));
    auto vec_word = createWordVector("../text.txt");
    auto table = createTable(vec_word);
    std::cout << generateText(table);
    return 0;
}
