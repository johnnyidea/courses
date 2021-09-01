//
// Created by rene on 9/1/21.
//
#include <vector>

#ifndef SORT_CONTAINERS_SORTING_METHODS_H
#define SORT_CONTAINERS_SORTING_METHODS_H

using Segment = std::vector<std::pair<int, int>>;



class SortingMethods
{
public:
    template <typename T>
    static void get_insertion(std::vector<T>& unsorted_value)
    {
        for (int i = 1; i < unsorted_value.size(); i++)
        {
            auto key = unsorted_value[i];
            auto j = i - 1;

            while (j >= 0 && unsorted_value[j] > key)
            {
                unsorted_value[j + 1] = unsorted_value[j];
                j--;
            }

            unsorted_value[j + 1] = key;
        }
    }
};

#endif //SORT_CONTAINERS_SORTING_METHODS_H
