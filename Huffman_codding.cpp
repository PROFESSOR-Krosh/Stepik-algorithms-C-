#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

typedef std::pair<std::string, int> Part;

bool Sort_by_value(const Part& a, const Part& b) {
	if (a.second != b.second) {
		return a.second < b.second;
	}
	return a.first < b.first;
}

bool Compare_pair_with_letter(const Part& a, std::string& b) {
	if (a.first.size() == 1) {
		if (a.first == b) {
			return true;
		}
	}
	return false;
}

bool Sort_pair_strings_by_value(const std::pair<std::string, std::string>& a, const std::pair<std::string, std::string>& b) {
	if (a.second != b.second) {
		return a.second < b.second;
	}
	return a.first < b.first;
}

bool Sort_by_key(const std::pair<std::string, std::string>& a, const std::pair<std::string, std::string>& b) {
	return a.first.size() < b.first.size();
}

int main() {
	std::string word;
	std::vector<Part> parts;
	std::vector<std::pair<std::string, std::string>> bin_parts;
	std::cin >> word;
	for (std::size_t i = 0; i < word.size(); ++i) {
		std::string s(1, word[i]);
		int flag = 1;
		for (std::size_t j = 0; j < parts.size(); ++j) {
			if (Compare_pair_with_letter(parts[j], s)) {
				parts[j].second += 1;
				flag = 0;
			}
		}
		if (flag == 1) {
			parts.push_back(std::make_pair(s, 1));
		}
	}

	if (parts.size() == 1) {
		bin_parts.push_back(std::make_pair(parts[0].first, "0"));
	} else {
		while (parts.size() > 1) {
			std::sort(parts.begin(), parts.end(), Sort_by_value);
			parts.push_back(Part(parts[0].first + parts[1].first, parts[0].second + parts[1].second));
			bin_parts.push_back(std::make_pair(parts[0].first, "0"));
			bin_parts.push_back(std::make_pair(parts[1].first, "1"));
			parts.erase(parts.begin(), parts.begin() + 2);
		}
	}
	int n = 0;
	std::vector<std::pair<std::string, std::string>> result;
	std::sort(bin_parts.begin(), bin_parts.end(), Sort_by_key);
	while (bin_parts[n].first.size() == 1) {
		result.push_back(std::make_pair(bin_parts[n].first, bin_parts[n].second));
		for (std::size_t i = n + 1; i < bin_parts.size(); ++i) {
			for (std::size_t j = 0; j < bin_parts[i].first.size(); ++j) {
				std::string s(1, bin_parts[i].first[j]);
				if (s == bin_parts[n].first) {
					result.at(n).second = bin_parts[i].second + result[n].second;
				}
			}
		}
		++n;
	}
	std::sort(result.begin(), result.end(), Sort_pair_strings_by_value);
	std::string bin_word;
	for (std::size_t i = 0; i < word.size(); ++i) {
		std::string s(1, word[i]);
		for (std::size_t j = 0; j < result.size(); ++j) {
			if (result[j].first == s) {
				bin_word += result[j].second;
			}
		}
	}

	std::cout << result.size() << " " << bin_word.size() << std::endl;
	for (std::size_t i = 0; i < result.size(); ++i) {
		std::cout << result[i].first << ": " << result[i].second << std::endl;
	}
	std::cout << bin_word << std::endl;
	return 0;
}