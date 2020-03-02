#ifndef QAHWA_SPLIT_LINE_HPP
#define QAHWA_SPLIT_LINE_HPP
#include<string>
#include<vector>


namespace Qahwa {

namespace strmanage {

std::vector<std::string> split_String(const std::string& line, const char& delimiter) {

	std::vector<std::string> result;
	std::string buffer;

	for (const char& Character : line) {
		if (((Character == delimiter) || (Character == '*')) && (buffer.empty())) continue;
		else if ((Character == delimiter) && (!buffer.empty())) {
			result.push_back(buffer);
			buffer.clear();
		}
		else {
			buffer.push_back(Character);
		}
	}
	if (!buffer.empty()) {
		result.push_back(buffer);
	}
	return result;
}

}
}

#endif /* QAHWA_SPLIT_LINE_HPP */
