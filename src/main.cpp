// Copyright dash 2021
#include "textgen.h"
std::map<prefix, std::vector<std::string>> statetab1;

int main() {
    prefix pr;
    //std::string f_("input.txt");
    std::string f_("f_input.txt");
    AddingToTab(f_);
    f_ = "f_out.txt";
    Generating(f_);
    return 0;
}