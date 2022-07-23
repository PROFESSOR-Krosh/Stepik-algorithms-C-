#include <iostream>
#include <utility>
#include <vector>
#include <iomanip>
#include <algorithm>

typedef std::pair <double, double> Object;

double Get_max_cost(const std::vector<Object>& objects, int& bag_capacity) {
	double result = 0;
	for (std::size_t i = 0; i < objects.size(); ++i) {
		if (bag_capacity >= objects[i].second) {
			result += objects[i].first;
			bag_capacity -= objects[i].second;
		} else if (bag_capacity > 0 && bag_capacity < objects[i].second) {
			result += (bag_capacity * objects[i].first) / objects[i].second;
			break;
		} else if (bag_capacity == 0) {
			break;
		}
	}
	return result;
}

bool Sort_objects(const Object& a, const Object& b) {
	return (a.first / a.second) > (b.first / b.second);
}

int main() {
	int objects_count;
	int bag_capacity;
	std::cin >> objects_count >> bag_capacity;
	std::vector<Object> objects(objects_count);
	for (int i = 0; i < objects_count; ++i) {
		std::cin >> objects[i].first >> objects[i].second;
	}
	std::sort(objects.begin(), objects.end(), Sort_objects);
	double cost = Get_max_cost(objects, bag_capacity);
	std::cout << std::fixed << std::setprecision(3) << cost << std::endl;
	return 0;
}