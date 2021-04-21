// Copyright 2021 valvarl

#ifndef INCLUDE_TEXTGEN_H_
#define INCLUDE_TEXTGEN_H_

#include <string>
#include <vector>
#include <deque>
#include <map>

typedef std::deque<std::string> prefix;  // очередь префиксов
static std::map<prefix, std::vector<std::string>> statetab;  // префикс-суффиксы

const int NPREF=2; // количество слов в префиксе
const int MAXGEN=100; //объем текста на выходе

void preprocess_table(const std::string& filename);
std::string generate(prefix &starting);

#endif  // INCLUDE_TEXTGEN_H_
