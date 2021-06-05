
#include <iostream>

#include "textgen.h"

int main() {

    setlocale(LC_ALL, "Russian");
    Markov_Model generator;

    generator.AddElements("source.txt");
    prefix start {"Girls", "with"};
    std::cout << generator.GenerateText();
    std::cout << std::endl;

    return 0;
}
