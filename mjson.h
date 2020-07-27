// mjson.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <vector>
#include <map>

enum class JType {
	JString,
	JNumber,
	JArray,
	JObject,
};


struct JSONValue {
	JType jtype;
	std::string value;
	std::vector<JSONValue> arr;
	std::map<std::string, JSONValue> objects;
};


// TODO: Reference additional headers your program requires here.
