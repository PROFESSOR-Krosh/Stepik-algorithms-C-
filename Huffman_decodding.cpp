#include <iostream>
#include <vector>
#include <string>
#include <utility>

typedef std::pair<std::string, std::string> Codding;

class Decodding {
public:
	void AddPair(const int& symb) {
		std::string s;
		std::string n;
		for (int i = 0; i < symb; ++i) {
			std::cin >> s >> n;
			s.pop_back();
			pair_of_sym.push_back(Codding(s, n));
		}
	}
	std::string Dec(const std::string& bin_word) {
		std::string s;
		std::string result;
		int flag = 1;
		for (std::size_t i = 0; i < bin_word.size(); ++i) {
			if (flag == 1) {
				s += bin_word[i];
			}
			for (auto item : pair_of_sym) {
				if (s == item.second) {
					result += item.first;
					flag = 0;
					s.clear();
				} else {
					flag = 1;
				}
			}
			if (s.size() == 0) {
				flag = 1;
			}
		}
		return result;
	}
private:
	std::vector<Codding> pair_of_sym;
};

int main() {
	int symb;
	int length;
	Decodding d;
	std::string bin_word;
	std::string word;
	std::cin >> symb >> length;
	d.AddPair(symb);
	std::cin >> bin_word;
	word = d.Dec(bin_word);
	std::cout << word;
	return 0;
}