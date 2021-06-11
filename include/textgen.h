#pragma once
//  Copyright 2021 idpas
#ifndef INCLUDE_TEXTGEN_H_
#define INCLUDE_TEXTGEN_H_

#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <map>
#include <fstream>
#include <ctime>

typedef std::deque<std::string> prefix;
static std::map<prefix, std::vector<std::string>> statetab;

const int NPREF = 2;
const int MAXGEN = 1000;

void text_generating(std::string &outputFile);
void add_to_state_tab(prefix &pr, std::string &s, std::string file_name);

#endif  //  INCLUDE_TEXTGEN_H_