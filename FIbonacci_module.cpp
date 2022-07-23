#include <cassert>
#include <iostream>

class Fibonacci {
 public:
  static int get_remainder(long long n, int m) {
    assert(n >= 1);
    assert(m >= 2);
    long long a = 0;
    long long b = 1;
    for (int i = 0; i < n; ++i) {
      b = a + b;
      a = b - a;
    }
    n = a;
    return n % m;
  }
};

int main(void) {
  long long n;
  int m;
  std::cin >> n >> m;
  std::cout << Fibonacci::get_remainder(n, m) << std::endl;
  return 0;
}