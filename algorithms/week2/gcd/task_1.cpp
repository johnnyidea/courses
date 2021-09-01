/*
 * По данным двум числам 1<= a,b <= 2*10^9 найдите их наибольший общий делитель.
 * Sample Input 1:  18 35
 * Sample Output 1: 1
 * Sample Input 2: 14159572 63967072
 * Sample Output 2: 4
 */

#include <cassert>
#include <cstdint>
#include <iostream>

template <class Int>
Int gcd(Int a, Int b) {
    assert(a > 0 && b > 0);

    //Realise via Euclid algorithm
    if (a == 0)
        return b;

    if (b == 0)
        return a;

    while (a != 0 && b!= 0)
        if (a >= b)
            a %= b;
        else
            b %= a;

    return a != 0 ? a : b;
}

int main(void) {
    std::int32_t a, b;
//    std::cin >> a >> b;
    std::cout << gcd(18 , 35) << "?= 1"<< std::endl;
    std::cout << gcd(14159572 , 63967072) << "?= 4"<< std::endl;
    return 0;
}