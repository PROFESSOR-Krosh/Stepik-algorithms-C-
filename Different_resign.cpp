#include <iostream>
#include <vector>

int main() {
	int num;
	std::cin >> num;
	std::vector<int> resign;
	for (int i = 1; i <= num; ++i) {
		if (2 * i + 1 > num) {
			if (i == num) {
				resign.push_back(i);
				break;
			} else {
				continue;
			}
		} else {
			resign.push_back(i);
			num -= i;
		}
	}
	std::cout << resign.size() << std::endl;
	for (auto item : resign) {
		std::cout << item << " ";
	}
	return 0;
}