#include <cassert>
#include <iostream>

class Fibonacci final {
public:
    static int get_last_digit(int n) {
        assert(n >= 1);
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
            array[i] = (array[i - 1]% 10 + array[i - 2]% 10) ;

        return array[n]%10;
    }
};

int main(void) {
    int n;
//    std::cin >> n;
    std::cout << Fibonacci::get_last_digit(841645) << std::endl;
    return 0;
}