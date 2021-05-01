#include <iostream>

#include "../include/textgen.h"

std::map<prefix, std::vector<std::string>> statetab1;


int main(int argc, char *argv[]) {
  prefix pr;
  std::string param(argv[1]);
  education(param);
  param = argv[2];
  generate(param);
  return 0;
}
