#include <iostream>
#include <vector>
#include <string>

class Bin_tree {
public:
	void Insert(const long& x) {
		bin_tree.push_back(x);
		for (std::size_t i = bin_tree.size(); i > 1; i /= 2) {
			if (bin_tree[i - 1] > bin_tree[(i / 2) - 1]) {
				bin_tree[i - 1] = bin_tree[(i / 2) - 1];
				bin_tree[(i / 2) - 1] = x;
			} else {
				break;
			}
		}
		/*for (const auto& item : bin_tree) {
			std::cout << item << " ";
		}
		std::cout << std::endl;*/
	}
	void ExtractMax() {
		if (bin_tree.size() != 0) {
			std::cout << bin_tree[0] << std::endl;
			bin_tree[0] = bin_tree[bin_tree.size() - 1];
			bin_tree.erase(bin_tree.end() - 1);
		}
		long i = 1;
		while (2 * i + 1 <= bin_tree.size()) {
			if (bin_tree[2 * i - 1] >= bin_tree[2 * i]) {
				if (bin_tree[2 * i - 1] > bin_tree[i - 1]) {
					long x = bin_tree[2 * i - 1];
					bin_tree[2 * i - 1] = bin_tree[i - 1];
					bin_tree[i - 1] = x;
				} else {
					break;
				}
				i = 2 * i;
			} else {
				if (bin_tree[2 * i] > bin_tree[i - 1]) {
					long x = bin_tree[2 * i];
					bin_tree[2 * i] = bin_tree[i - 1];
					bin_tree[i - 1] = x;
				} else {
					break;
				}
				i = 2 * i + 1;
			}
		}
		if (2 * i == bin_tree.size()) {
			if (bin_tree[2 * i - 1] > bin_tree[i - 1]) {
				long x = bin_tree[2 * i - 1];
				bin_tree[2 * i - 1] = bin_tree[i - 1];
				bin_tree[i - 1] = x;
			}
		}
		/*for (const auto& item : bin_tree) {
			std::cout << item << " ";
		}
		std::cout << std::endl;*/
	}
private:
	std::vector<long> bin_tree;
};

int main() {
	long n;
	std::string operation;
	Bin_tree bt;
	std::cin >> n;
	for (n; n > 0; --n) {
		std::cin >> operation;
		if (operation == "Insert") {
			long x;
			std::cin >> x;
			bt.Insert(x);
		} else if (operation == "ExtractMax") {
			bt.ExtractMax();
		} else {

		}
	}
	return 0;
}