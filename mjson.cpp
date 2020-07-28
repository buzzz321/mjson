// mjson.cpp : Defines the entry point for the application.
//

#include <ctype.h>
#include <iostream>
#include "mjson.h"

using namespace std;

void check(bool result, std::string expected, std::string actual) {
	if (result) {
		std::cout << "\033[42m " << expected << "\033[m" << std::endl;
	}
	else {
		std::cout << "Wanted: "<< expected <<" but got " << "\033[41m " << actual << "\033[m" << std::endl;
	}
}

int main()
{
	check(true, "wanted", "got");
	check(false, "wanted", "got");
	
	return 0;
}
