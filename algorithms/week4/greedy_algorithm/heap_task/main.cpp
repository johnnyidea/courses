/*
 * Первая строка входа содержит число операций 1 <= n <= 10^5
 . Каждая из последующих nn строк задают операцию одного из следующих двух типов:
 * Insert x
 * ExtractMax.
 * Первая операция добавляет число xx в очередь с приоритетами, вторая — извлекает максимальное число и выводит его.
 */
#include <iostream>
#include <utility>
#include <vector>
#include <iostream>

#include <cassert>

#include <iostream>
#include <cmath>

using namespace std;

class Heap
{
public:
    void insert(const int& val)
    {
        _heap_array.push_back(val);

        if (_heap_array.size() > 1)
            _shift_up();
    }

    int extract()
    {
        swap(_heap_array.front(), _heap_array.back());
        auto res = move(_heap_array.back());
        _heap_array.pop_back();
        _shift_down();
        return res;
    }

private:
    vector<int> _heap_array;

    void _shift_up()
    {
        int i = _heap_array.size();
        auto j = i;
        auto tmp = int((i/2.0 - 1));
        while (tmp >= 0 && _heap_array[tmp] < _heap_array[j-1])
        {
            swap(_heap_array[tmp], _heap_array[j-1]);
            i = ceil((i/2.0) - 1);
            tmp = ceil((i/2.0 - 1));
            j = i + 1;
        }
    }

    void _shift_down()
    {
        auto i{0};
        auto sz = _heap_array.size();
        while (2*i + 1 < sz)
        {
            auto left = 2*i + 1;
            auto right = 2*i + 2;
            auto j = left;

            if (right < sz && _heap_array[left] < _heap_array[right])
                j = right;

            if (_heap_array[j] <= _heap_array[i])
                break;

            swap(_heap_array[j], _heap_array[i]);
            i = j;
        }
    }
};

int main(void)
{
    Heap heap;

    int numbers;
    string operation;

    cin >> numbers;
    for (int i = 0; i < numbers; i++)
    {
        cin >> operation;
        if (operation.find("Insert") != string::npos)
        {
            int val;
            cin >> val;
            heap.insert(val);
        } else if (operation.find("ExtractMax") != string::npos)
            cout << heap.extract() << endl;
    }

//    heap.insert(1);
//    heap.insert(0);
//    heap.insert(2);
//    heap.insert(10);
//    heap.insert(10);
//
//    cout << heap.extract() << endl;
//    cout << heap.extract() << endl;
//    cout << heap.extract() << endl;
//    cout << heap.extract() << endl;

    return 0;
}