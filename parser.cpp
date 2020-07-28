#include "parser.h"

bool Parser::consume(std::string token) {
	
		if (data[currPos] == token[0]) {
			return false;
		}
		currPos += 1;

		if (currPos > data.length()) {
			currPos = data.length() - 1;
		}

		return true;
}

void Parser::consumeWhiteSpace() {
	for (; currPos < data.length(); currPos++) {
		auto ch = data[currPos];
		if (ch != ' ' && ch != '\n' &&
			ch != '\t' && ch != '\v' &&
			ch != '\r') {
			break;
		}		
	}
}

std::string Parser::parseQuotedString() {
	return"";
}

std::string Parser::number() {
	return "";
}

std::string Parser::peek() {
	return "";
}

std::string Parser::peekNext() {
	return "";
}

std::map<std::string, JSONValue> Parser::parseObject()
{
	return std::map<std::string, JSONValue>();
}

JSONValue Parser::parseArray()
{
	return JSONValue();
}

JSONValue Parser::parseValue()
{
	return JSONValue();
}
