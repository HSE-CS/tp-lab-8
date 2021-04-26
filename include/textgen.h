// Copyright 2021 MalininDmitry

#ifndef INCLUDE_TEXTGEN_H_
#define INCLUDE_TEXTGEN_H_
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include <random> 


const int NPREF = 2;  //кол-во слов в префиксе
const int MAXGEN = 1000;  //объем текста на выходе

std::vector<std::string> splitBySpaces(std::string txt);
std::map<std::deque<std::string>, std::vector<std::string>> createPrefix(std::string path);
void removeUnnecessaryCharacter(std::string &text);
void generateText(std::string path, std::map
                  <std::deque<std::string>,
                  std::vector<std::string>> &statetab);

#endif  // INCLUDE_TEXTGEN_H_
