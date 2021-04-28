// Copyright 2021 valvarl

#include <iostream>
#include "textgen.h"

int main(int argc, char* argv[]) {
    preprocess_table("BonesLyricsClean.txt", &statetab);
    prefix st{"johnny", "cage", "black"};
    std::cout << generate(st, &statetab);
}