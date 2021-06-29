#include <cassert>
#include <cstdint>
#include <iostream>

using namespace std;

class Fibonacci final {
public:
    static int get_remainder(int64_t n, int m) {
        assert(n >= 1);
        assert(m >= 2);

        if (n == 1)
            return 1;

        int main_size = 6*m > 5000 ? 6*m: 5000;

        uint64_t array[main_size];

        array[0] = 0;
        array[1] = 1;

        uint period{0};

        for (int64_t i = 2; i <= main_size; i++)
        {
            array[i] = (array[i-1] + array[i-2])%m;

            period = define_period(array, i);

            if (period == 0)
                continue;

            return array[n%period];
        }

        int cur       {0};
        int prev      {1};
        int prev_prev {0};

        for (int64_t i = 2; i <= main_size; i++)
        {
            cur = (prev + prev_prev);
            prev_prev = prev;
            prev = cur;
        }

        return cur%m;
    }

    static uint define_period(uint64_t array[], int64_t sz)
    {
        uint min_period{2};

        for (uint p = min_period; p <= sz/2; p++)
            for (uint i = 0; i <= p; i++)
            {
                if (array[i] != array[i + p + 1])
                    break;

                if (i == p)
                    return p+1;
            }

        return 0;
    }
};

int main(void) {
    int64_t n;
    int m;
//    std::cin >> n >> m;
    std::cout << Fibonacci::get_remainder(60282445765134413, 2263) << "?= 974" << std::endl;
    std::cout << Fibonacci::get_remainder(1598753, 25897) << "?= 20305" << std::endl;
    std::cout << Fibonacci::get_remainder(10, 4) << "?= 3" << std::endl;
    std::cout << Fibonacci::get_remainder(200, 10) << "?= 5" << std::endl;
    std::cout << Fibonacci::get_remainder(12589, 369) << "?= 89" << std::endl;

    return 0;
}