#include "parser.h"
#include <cctype>
Parser::Parser(std::string data) :data(data) {}

bool Parser::consume(std::string token) {

	if (data[currPos] != token[0]) {
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
	consumeWhiteSpace();

	if (!consume("\"")) {
		return "";
	}

	auto startpos = currPos;
	auto endFound = false;

	while (currPos < data.length()) {
		if (data[currPos] == '\"') {
			endFound = true;
			break;
		}
		currPos++;
	}
	if (endFound) {
		if (!consume("\"")) {
			std::cout << " Error end not found?!?" << std::endl;
			return "";
		}
		return data.substr(startpos, currPos - startpos - 1);
	}
	return"";
}

std::string Parser::parseNumber() {
	consumeWhiteSpace();

	auto startpos = currPos;
	auto endFound = false;

	while (currPos < data.length()) {
		auto ch = data[currPos];

		if (ch == '.' || ch == '-') {
			currPos++;
			continue;
		}
		if (!std::isdigit(ch)) {
			endFound = true;
			break;
		}
		currPos++;
	}

	return data.substr(startpos, currPos - startpos);
}

char Parser::peek() {
	auto retVal = data[currPos];
	return retVal;
}

char Parser::peekNext() {
	auto retVal = data[(currPos + 1 < data.length()) ? currPos + 1 : currPos];
	return retVal;
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
