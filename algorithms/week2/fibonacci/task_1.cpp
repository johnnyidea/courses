#include <cassert>
#include <iostream>

class Fibonacci final {
 public:
  static int get(int n) {
    assert(n >= 0);
    // put your code here
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    auto size = n + 1;

    int array[size];

    array[0] = 0;
    array[1] = 1;

    for (int i = 2; i <= n; i++)
        array[i] = array[i - 1] + array[i - 2];

    return array[n];
  }
};

int main(void) {
  int n;
//  std::cin >> n;
  std::cout << Fibonacci::get(4) << std::endl;
  return 0;
}
