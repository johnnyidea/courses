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

        int64_t size = n + 1;

        uint64_t array[size];
        uint64_t mod_array[size];

        array[0] = 0;
        array[1] = 1;

        mod_array[0] = 0;
        mod_array[1] = 1;

        uint period{0};

        for (int64_t i = 2; i <= n; i++)
        {
            array[i] = (array[i - 1] + array[i - 2]);

            mod_array[i] = array[i] % m;

            period = define_period(mod_array, i);

            if (period == 0)
                continue;

            cout <<"period:" << period << endl;
            return mod_array[n%period];
        }

        return 0;
    }

    static uint define_period(uint64_t array[], int64_t sz)
    {
        uint period{0};

        uint min_period{2};

        for (uint p = min_period; p < sz/2; p++)
        {
            for (uint i = 0; i <= p; i++)
            {
                if (array[i] != array[i + p + 1])
                    break;

                if (i == p)
                    return p + 1;
            }
        }

        return period;
    }
};

int main(void) {
    int64_t n;
    int m;
//    std::cin >> n >> m;
    std::cout << Fibonacci::get_remainder(200, 10) << std::endl;
//    std::cout << Fibonacci::get_remainder(12589, 369) << std::endl;

    return 0;
}