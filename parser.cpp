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