// Copyright 2021 Elise
#include "textgen.h"

std::string read_text(std::string input_file) {
  std::string aa;
  std::string text = "";
  std::ifstream input(input_file);
  if (input.is_open()) {
    while (!input.eof()) {
      input >> aa;
      text = text + aa + ' ';
    }
  }
  input.close();
  return text;
}

void make_table(std::string text) {
  int i = 0, porition = 0, count = -1;
  while (text[i] != '\0') {
    if (text[i] != ' ' && text[i] != '\r' && text[i] != '\n' && porition == 0) {
      porition = 1;
      count++;
      buff.push_back("");
      buff[count] = buff[count] + text[i];
    } else if ((text[i] == ' ' || text[i] == '\r' || text[i] == '\n') &&
               porition == 1) {
      porition = 0;
    } else if (text[i] != ' ' && text[i] != '\r' && text[i] != '\n' &&
                porition == 1) {
      buff[count] = buff[count] + text[i];
    }
    i++;
  }
  for (int i = 0; i < buff.size() - NPREF + 1; i++) {
    prefix pref;
    for (int j = 0; j < NPREF; j++) {
      pref.push_back(buff[i + j]);
    }
    if (i + NPREF < buff.size())
      statetab[pref].push_back(buff[i + NPREF]);
    else
      statetab[pref].push_back("END_OF_FILE");
  }
}

std::string make_new_text() {
  prefix pref;
  for (int i = 0; i < NPREF; i++) pref.push_back(buff[i]);
  std::string total = "";
  int count = 1;

  while (total.size() < MAXGEN) {
    if (total.size() == 0) {
      for (int i = 0; i < NPREF; i++) {
        total = total + pref[i] + ' ';
      }
    }
    int rand_;
    if (statetab[pref][0] == "END_OF_FILE" && statetab[pref].size() == 1) {
      break;
    }

    if (statetab[pref].size() == 0) {
      break;
    }

    rand_ = rand() % statetab[pref].size();
    if (statetab[pref][statetab[pref].size() - 1] == "END_OF_FILE") {
      rand_ = rand() % (statetab[pref].size() - 1);
    }
    total = total + statetab[pref][rand_] + ' ';
    if (count * 100 - total.size() < 0 || count * 100 - total.size() > 100) {
      count++;
      total = total + '\n';
    }
    std::string tmp = statetab[pref][rand_];
    for (int i = 0; i < NPREF - 1; i++) {
      pref[i] = pref[i + 1];
    }
    pref[NPREF - 1] = tmp;
  }
  return total;
}

void write_text_to_file(std::string total) {
  std::ofstream output;
  output.open("output.txt");
  if (output.is_open()) {
    output << total;
  }
  output.close();
}
