// Copyright 2021 Elise
#include "textgen.h"

int main() {

  std::string test = read_text("input.txt");
  make_table(test);
  std::string result = make_new_text();
  write_text_to_file(result);
  return 0;
}
