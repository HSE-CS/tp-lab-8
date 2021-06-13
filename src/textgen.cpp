#include "textgen.h"
#include <string>

void createTable(std::string t) {
    int p = 0;
    int i = 0;
    int c = -1;
    while (t[i] != '\0') {
        if (t[i] != '\r' && t[i] != '\n' && t[i] != ' ' && p == 0) {
            p = 1;
            c++;
            b.push_back("");

            b[c] += t[i];
        }
        if ((t[i] == '\r' || t[i] == ' ' || t[i] == '\n') && p == 1) {
            p = 0;
        }
        if (t[i] != ' ' && t[i] != '\r' && t[i] != '\n' && p == 1) {
            b[c] += t[i];
        }
        ++i;
    }

    for (int i = 0; i < b.size() - NPREF + 1; i++) {
        prefix p;
        for (int j = 0; j < NPREF; j++) {
            p.push_back(b[i + j]);
        }
        if (i + NPREF < b.size()) {
            statetab[p].push_back(b[i + NPREF]);
        }
        else {
            statetab[p].push_back("END");
        }
    }
}

std::string createText() {
    prefix p;
    for (int i = 0; i < NPREF; i++) {
        p.push_back(b[i]);
    }
    int c = 1;
    std::string result;
    while (result.size() < MAXGEN) {
        if (result.size() == 0) {
            for (int i = 0; i < NPREF; i++) {
                result = result + p[i] + ' ';
            }
        }
        int randomValue = 0;
        if (statetab[p][0] == "END" && statetab[p].size() == 1) {
            break;
        }

        if (statetab[p].size() == 0) {
            break;
        }

        randomValue = rand() % statetab[p].size();
        if (statetab[p][statetab[p].size() - 1] == "END") {
            randomValue = rand() % (statetab[p].size() - 1);
        }
        result = result + statetab[p][randomValue] + ' ';
        if (c * 100 - result.size() < 0 || c * 100 - result.size() > 100) {
            c++;
            result = result + '\n';
        }
        std::string tmp = statetab[p][randomValue];
        for (int i = 0; i < NPREF - 1; i++) {
            p[i] = p[i + 1];
        }
        p[NPREF - 1] = tmp
    }
    return result;
}
