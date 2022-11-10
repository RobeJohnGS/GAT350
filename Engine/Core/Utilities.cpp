#include "Utilities.h"
#include <algorithm>

namespace JREngine {
	std::string ToLower(const std::string& str)
	{
		
		std::string lower = str;
		/*for (size_t i = 0; i < lower.size(); i++) {
			lower[i] = std::tolower(lower[i]);
		}*/
		std::transform(lower.begin(), lower.end(), lower.begin(), [](unsigned char c) {return std::tolower(c); });
		return lower;
	}
	std::string ToUpper(const std::string& str)
	{
		std::string upper;
		std::transform(upper.begin(), upper.end(), upper.begin(), [](unsigned char c) {return std::toupper(c); });
		return upper;
	}
	bool CompareIgnoreCase(const std::string& str1, const std::string& str2)
	{
		if (str1.length() != str2.length()) {
			return false;
		}

		return std::equal(str1.begin(), str1.end(), str2.begin(), [](char c1, char c2) {
			return (std::tolower(c1) == std::tolower(c2));
			});
	}
}