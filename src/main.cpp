//  Copyright 2021 GHA created by Klykov Anton

#include "textgen.h"

int main() {
  Analyze analyze;
  analyze.ReadFile();
  analyze.Generate();
  return 0;
}
