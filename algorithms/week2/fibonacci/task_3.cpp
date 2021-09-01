#include <cassert>
#include <cstdint>
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

class Fibonacci final {
public:
    static int get_remainder(int64_t n, int m) {
        assert(n >= 1);
        assert(m >= 2);

        if (n == 1)
            return 1;

        int main_size = 6*m > 100 ? 6*m: 100;

        uint64_t * array = new uint64_t [main_size]{0, 1};

        uint period{0};

        for (int64_t i = 2; i <= main_size; i++)
        {
            array[i] = (array[i-1] + array[i-2])%m;

            if (array[i] == 0 && array[i - 1] == 1)
                    period = i;

            if (period == 0)
                continue;

            return array[n%period];
        }

        return array[n%m];
    }
};

int main(void) {
    int64_t n;
    int m;
//    std::cin >> n >> m;
    std::cout << Fibonacci::get_remainder(60282445765134413, 2263) << "?= 974" << std::endl;
    std::cout << Fibonacci::get_remainder(1598753, 25897) << "?= 20305" << std::endl;
    // std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << Fibonacci::get_remainder(10, 4) << "?= 3" << std::endl;
    std::cout << Fibonacci::get_remainder(200, 10) << "?= 5" << std::endl;
    std::cout << Fibonacci::get_remainder(12589, 369) << "?= 89" << std::endl;


    for (int i = 10; i < 1e6; i++)
        Fibonacci::get_remainder(i, 10);

    return 0;
}