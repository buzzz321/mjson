#pragma once

#include "mjson.h"

class Parser {
public:
	Parser(std::string data);
	bool consume(std::string token);
	void consumeWhiteSpace();
	std::string parseQuotedString();
	std::string parseNumber();
	char peek();
	char peekNext();
	std::map<std::string, JSONValue> parseObject();
	JSONValue parseArray();
	JSONValue parseValue();

	std::string getData() const { return data; }
	size_t getcurrPos() const { return currPos; }
private:
	std::string data;	
	size_t currPos{ 0 };
};