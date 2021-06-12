// Copyright 02.05.21 Lavrov Artyom

#include "textgen.h"

int main() {
	TextGen text1;
	text1.setPath();
	text1.ReadText();
	std::cout << text1.getCount() << std::endl;
	std::cout << "Input Text example:" << std::endl;
	text1.printText();
	text1.makePairs();
	std::cout << std::endl << "Example of work:" << std::endl;
	std::cout << text1.createText(5);
	return 0;
}