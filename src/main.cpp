//  Copyright Baklanov 2021
#include "Textgen.h"
#include <iostream>
#include <fstream>


int main() {
	std::map<prefix, std::vector<std::string> > statetab;
	const int NPREF = 2;
	const int MAXGEN = 1000;
	std::string fin = "text.txt";
	statetab = makeStatetab(NPREF, MAXGEN, fin);
	prefix startPref = { "There", "are" };
	auto it = statetab.find(startPref);
	std::cout << it->first.size() << "\n\n";
	for (auto it : startPref) {
		std::cout << it << " ";
	}
	for (int i = 0; i < MAXGEN; ++i) {
		std::string somestring =
			generateText(&statetab, &startPref);
		if (somestring.length()) {
			std::cout << somestring << " ";
			startPref.erase(startPref.begin());
			startPref.push_back(somestring);
		}
	}
	std::cout << statetab.size() << std::endl;
	
}