// Copyright 2021 Panina Polina
#include <iostream>
#include "textgen.h"

int main() { 
  prefix pref;
  std::string file("file_in.txt");
  add_to_tab(file);
  file = "file_out.txt";
  generate(file);
  return 0;
}
