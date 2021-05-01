// Copyright 2021 Kuznetsov Mikhail
#include <iostream>
#include <ctime>
#include "textgen.h"

int main() {
  srand(time(nullptr));
  if (createStateTab("../data/input.txt")) {
    std::cout << "StateTab was created!" << std::endl;
  }
  if (generateText("../data/output.txt")) {
    std::cout << "Text was generated!" << std::endl;
  }
  return 0;
}


