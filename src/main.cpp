//  Copyright 2021 Urtyukov Ilya
#include <iostream>
#include "textgen.h"

std::map<prefix, std::vector<std::string>> statetab1;


int main() {
  prefix pr;
  std::string param("in.txt");
  addToStadeTab(param);
  param = "out.txt";
  generate(param);
  return 0;
} 
