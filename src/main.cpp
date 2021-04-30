#include <fstream>
#include <iostream>
#include <sstream>

#include "textgen.h"

int main(int argc, char* argv[]) {
  if (argc < 4) {
    std::cout << "USAGE: " << argv[0] << " PREFIX_SIZE WORD_COUNT FILE";
    return 0;
  }
  size_t wordCount, prefixSize;
  {
    std::stringstream tmp{argv[1]};
    tmp >> prefixSize;
  }
  {
    std::stringstream tmp{argv[2]};
    tmp >> wordCount;
  }
  std::fstream f(argv[3]);
  std::string text;
  {
    std::string tmp;
    while (f >> tmp) {
      text.append(tmp);
      text.append(" ");
    }
    text.pop_back();
  }
  MarkovMap map = generateWordMap(text, prefixSize);
  std::cout << markov(map, wordCount) << std::endl;
  return 0;
}