// Copyright 2021 Egor Buzanov

#include "../include/textgen.h"

int main() {
  createStateTab("../include/text.txt");
  std::cout << makeText << std::endl;
  return 0;
}
