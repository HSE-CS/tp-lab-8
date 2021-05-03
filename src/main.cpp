// Copyright 2021 Lab8 TiNa
#include "textgen.h"

//std::map<prefix, std::vector<std::string>> statetabb;

int main() {
  prefix pr;
  std::string filent("filein.txt");
  add_to_tab(filent);
  filent = "fileout.txt";
  generate_text(filent);
  return 0;
}