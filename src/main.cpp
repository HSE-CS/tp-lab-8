// Copyright 2021 by Liza
#include "textgen.h"

int main() {
TextGeneration make;
std::string text = make.ReadFromFile("mytext.txt");
make.MakingTheTable(text);
return 0;}
