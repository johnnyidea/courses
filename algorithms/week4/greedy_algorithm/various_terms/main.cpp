#include <iostream>
#include <vector>

using namespace std;

void print_vec(std::vector<int> vec)
{
    for (const auto it: vec)
        cout << it << "\t";

    cout << endl;
}

std::vector<int> get_terms(int n)
{
    std::vector<int> res;
    res.reserve(n);

    for (int i = 1; i <= n; i++)
        if ((n - i) >= (i + 1))
        {
            res.push_back(i);
            n -= i;
        } else
        {
            res.push_back(n);
            return res;
        }

    return res;
}

int main(void)
{
    auto num{0};
    std::cin >> num;

    auto res = get_terms(num);

    cout << res.size() << endl;
    print_vec(res);

    return 0;
}