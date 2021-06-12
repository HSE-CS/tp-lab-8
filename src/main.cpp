//  Copyright 2021 idpas
#include "textgen.h"

std::map<prefix, std::vector<std::string>> statetab1;

int main() {
  prefix pref;
  std::string name("input.txt");
  add_to_state_tab(pref, name);
  name = "output.txt";
  text_generating(name);
  return 0;
	return 0;
}
