#pragma once

#include "mjson.h"

class Parser {
public:
	bool consume(std::string token);
	void consumeWhiteSpace();
	std::string parseQuotedString();
	std::string number();
	std::string peek();
	std::string peekNext();
	std::map<std::string, JSONValue> parseObject();
	JSONValue parseArray();
	JSONValue parseValue();

	std::string getData() const { return data; }
	size_t getcurrPos() const { return currPos; }
private:
	std::string data;	
	size_t currPos{ 0 };
};