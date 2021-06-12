// Copyright KarMashanova 2021
#include "textgen.h"
std::map<prefix, std::vector<std::string>> statetab1;

int main() {
    prefix pr;
    std::string f_("f_input.txt");
    AddTab(f_);
    f_ = "f_out.txt";
    Generating(f_);
    return 0;
}