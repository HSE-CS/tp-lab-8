// Copyright 2021 alexgiving

#include "textgen.h"

int main() {
  Analyze analyze;
  analyze.ReadFile();
  analyze.Generate();
  return 0;
}
