//  Copyright 2021 Longa_Bonga
#include "textgen.h"

int main() {
  srand(time(NULL));
  std::map<prefix, std::vector<std::string>> statetab;
  fulfilStatetab(statetab, "ProgTech/Lab8/text.txt");
  prefix start;
  std::cout << "Enter" << NPREF << "words" << std::endl;
  for (size_t i = 0; i < NPREF; ++i) {
    std::string pref;
    std::cin >> pref;
    start.push_back(pref);
  }
  generateText(statetab, start, "outT.txt");
  return 0;
}