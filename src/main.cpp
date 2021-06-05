
#include <iostream>

#include "textgen.h"

int main() {

    setlocale(LC_ALL, "Russian");
    Markov_Model generator;

    generator.AddElements("russian-source.txt");

    generator.GenerateText();
    std::cout << std::endl;

    return 0;
}
