// mjson.cpp : Defines the entry point for the application.
//

#include <ctype.h>
#include <iostream>
#include "mjson.h"
#include "parser.h"

using namespace std;

void check(bool result, std::string expected, std::string actual) {
	if (result) {
		std::cout << "\033[42m " << "Pass" << "\033[m" << std::endl;
	}
	else {
		std::cout << "Wanted: "<< expected <<" but got " << "\033[41m " << actual << "\033[m" << std::endl;
	}
}

void testParseQuotedString() {
	Parser uat(" \"hej och hopp\" ");

	uat.consumeWhiteSpace();

	auto result = uat.parseQuotedString();

	check(result == "hej och hopp", "hej och hopp", result);
}

void testParseNumber() {
	{
		Parser uat(" 123.4 ");

		uat.consumeWhiteSpace();
		auto result = uat.parseNumber();

		check(result == "123.4", "123.4", result);
	}

	{
		Parser uat("123.4");

		uat.consumeWhiteSpace();
		auto result = uat.parseNumber();

		check(result == "123.4", "123.4", result);
	}
}

int main()
{

	testParseQuotedString();
	testParseNumber();
	return 0;
}
