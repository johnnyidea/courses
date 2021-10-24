#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

struct Item final {
    int weight;
    int value;
};

void sort_items(std::vector <Item>& items)
{
    for (int i = 1; i < items.size(); i++)
    {
        auto key = items[i];
        auto j = i - 1;

        while (j >= 0 && (static_cast<double>(key.value) / key.weight) > (static_cast<double>(items[j].value)/items[j].weight))
        {
            items[j + 1] = items[j];
            j--;
        }

        items[j + 1] = key;
    }
}

double get_max_knapsack_value(int capacity, std::vector <Item> items)
{
    double value = 0.0;

    sort_items(items);
    // take items while there is empty space in knapsack
    for (auto &item:items) {
        if (capacity > item.weight)
        {
            // can take full item and continue
            capacity -= item.weight;
            value += item.value;
        } else
        {
            value += item.value * (static_cast <double>(capacity) / item.weight);
            break;
        }
    }

    return value;
}

int main(void)
{
    //-------------------------------------------------------------------------
    int knapsack_capacity{50};
    std::vector <Item> items {{ 20, 60},
                              {50,  100},
                              {30, 120}};


    double max_knapsack_value = get_max_knapsack_value(knapsack_capacity, std::move(items));

    std::cout.precision(10);
    std::cout << max_knapsack_value << std::endl;
    //-------------------------------------------------------------------------
    knapsack_capacity = 9022;
    items =     {{1601, 3316},
                 {8940, 5375},
                 {6912, 2852},
                 {9926, 3336},
                 {8427, 1717}};

    for (const auto it: items)
        std::cout << static_cast<double>(it.value) / it.weight << std::endl;


    max_knapsack_value = get_max_knapsack_value(knapsack_capacity, std::move(items));
    std::cout.precision(10);
    std::cout << max_knapsack_value << std::endl;

    return 0;
}