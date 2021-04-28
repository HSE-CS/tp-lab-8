#include <fstream>
#include <deque>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <list>
#include <iterator>
#include "textgen.h"



int main() {
    setlocale(LC_ALL, "Russian");
    const char* link = "text.txt";
    MarckovChair demo(link, 1, 200);
    std::string result = demo.getResult();
    std::cout << result;
    return 0;
}

