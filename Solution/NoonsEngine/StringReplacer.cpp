#include "StringReplacer.h"

std::string Noon::Util::ReplaceAllChar(std::string & replacedStr, std::string from, std::string to)
{
	unsigned int pos = replacedStr.find(from);
	int toLen = to.length();

	if (from.empty()) {
		return replacedStr;
	}

	while ((pos = replacedStr.find(from, pos)) != std::string::npos) {
		replacedStr.replace(pos, from.length(), to);
		pos += toLen;
	}
	return replacedStr;
}
