// Copyright 2021 DB

#include "textgen.h"

int main() {
  MarkovChain a;
  a.MakeTable("input.txt");
  std::string b = a.CreateNewText();
  std::cout << b;
  std::cout << a.MakeTableInt("input.txt") << std::endl;
  return 0;
}
