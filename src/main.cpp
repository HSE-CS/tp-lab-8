#include "textgen.h"
#include <string>
#include <random>

int main() {
    srand(time(0));
    std::string output;
    std::string tmp;
    std::ifstream input("input.txt");
    while (!input.eof()) {
        input >> tmp;
        output = output + tmp + ' ';
    }
    input.close();
    createTable(output);
    std::string result = createTet();
    std::cout << result << std::endl;
    return 0;
}
