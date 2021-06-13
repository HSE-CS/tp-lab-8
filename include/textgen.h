// Copyright 2021 ch2oh-ch2oh

#ifndef TP_LAB_8_TEXTGEN_H
#define TP_LAB_8_TEXTGEN_H

#include <deque>
#include <fstream>
#include <iostream>
#include <map>
#include <random>
#include <string>
#include <vector>

const int NPREF = 2;      // количество слов в префиксе
const int MAXGEN = 1000;  //объем текста на выходе

typedef std::deque<std::string> prefix;  // очередь префиксов

unsigned int seed = 148;

prefix map_fill(const std::string&,
                std::map<prefix, std::vector<std::string>>*);
std::string read_file(const std::string&);
void print_state(std::map<prefix, std::vector<std::string>>*);
std::string generate(const std::map<prefix, std::vector<std::string>>&,
                     const prefix&);

#endif  // TP_LAB_8_TEXTGEN_H
