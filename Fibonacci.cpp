#include <cassert>
#include <iostream>
#include <vector>

class Fibonacci {
 public:
  static int get(int n) {
    assert(n >= 0);
    std::vector<int> fib;
    fib.push_back(0);
    fib.push_back(1);
    for (int i = 2; i <= n; ++i) {
      fib.push_back(fib[i - 1] + fib[i - 2]);
    }
    n = fib[n];
    return n;
  }
};

int main(void) {
  int n;
  std::cin >> n;
  std::cout << Fibonacci::get(n) << std::endl;
  return 0;
}