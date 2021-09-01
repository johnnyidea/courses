//
// Created by Rene on 9/1/21.
//
#include "sorting_methods.h"

#include <iostream>

using namespace std;

template <typename T>
void print(const T& vals)
{
    for (const auto v: vals)
        cout << v << "\t";

    cout << endl;
}

int main(void)
{
    vector<int> arr = {5, 4, 3, 2, 1};

    print(arr);

    SortingMethods::get_insertion(arr);

    print(arr);

    return 0;
}