// Copyright 02.05.21 Lavrov Artyom

#ifndef INCLUDE_TEXTGEN_H_
#define INCLUDE_TEXTGEN_H_
#include <iostream>
#include <string>
#include <deque>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
typedef std::deque<std::string> prefix;

class TextGen {
private:
	int wordcount = 0;
	std::string path;
	const int NPREF = 2;
	const int MAXGEN = 1000;
	std::vector <std::string> text;
	std::map<prefix, std::vector<std::string>> statetab;

public:
	void setPath(std::string from = "../src/input.txt");
	void ReadText();
	void printText();
	std::string getPath();
	int getCount();
	void makePairs();
	std::string createText(int words = INT8_MAX);
};

#endif  // INCLUDE_TEXTGEN_H_