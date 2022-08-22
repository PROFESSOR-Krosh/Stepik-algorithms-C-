#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

int get_pos(const std::vector<long> &numbers, long number) {
  size_t l = 1;
  size_t r = numbers.size(); 
  while (l <= r) {
    size_t m = (l + r) / 2;
    if (numbers[m - 1] == number) {
      return m;
    } else if (numbers[m - 1] > number) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  return -1;
}

int main(void) {
  size_t number_count;
  std::cin >> number_count;
  std::vector<long> numbers(number_count);
  for (size_t i = 0; i < number_count; i++) {
    std::cin >> numbers[i];
  }

  size_t query_count;
  std::cin >> query_count;
  while (query_count-- > 0) {
    long number;
    std::cin >> number;
    std::cout << get_pos(numbers, number) << " ";
  }
  std::cout << std::endl;
}