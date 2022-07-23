#include <cassert>
#include <iostream>

class Fibonacci {
 public:
  static int get_last_digit(int n) {
    assert(n >= 1);
    int a = 0;
    int b = 1;
    for (int i = 0; i < n; ++i) {
      b = a + b;
      a = (b - a) % 10;
    }
    if (n >= 2) {
      n = a;
    }
    return n;
  }
};

int main(void) {
  int n;
  std::cin >> n;
  std::cout << Fibonacci::get_last_digit(n) << std::endl;
  return 0;
}