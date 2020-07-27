#pragma once

#include "mjson.h"

class Parser {
public:
	bool consume(std::string token);
	void consumeWhiteSpace();
private:
	std::string data;	
	uint32_t currPos{ 0 };
};