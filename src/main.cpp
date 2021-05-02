// Copyright 2021 GHA Test Team
#include <iostream>

#include "../include/textgen.h"

int main(int argc, char *argv[]) {
  prefix pr;
  std::string param(argv[1]);
  education(param);
  param = argv[2];
  generate(param);
  return 0;
}
