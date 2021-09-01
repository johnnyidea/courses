
//По данным n отрезкам необходимо найти множество точек минимального размера,
//для которого каждый из отрезков содержит хотя бы одну из точек.
//В первой строке дано число 1≤n≤100 отрезков. Каждая из последующих n строк содержит по два числа 0 <= l <= r <= 10^9
//, задающих начало и конец отрезка. Выведите оптимальное число m точек и сами m точек. Если таких множеств точек несколько, выведите любое из них.

#include <iostream>
#include <utility>
#include <vector>
#include <iostream>

#include <cassert>

using namespace std;

using Segment = std::pair<int, int>;

void print(const std::vector<Segment>& vals)
{
    for (const auto v: vals)
        cout << v.first << " " << v.second << endl;

    cout << endl;
}

static void sort_insertion(std::vector<Segment>& unsorted_value)
{
    for (int i = 1; i < unsorted_value.size(); i++)
    {
        auto key = unsorted_value[i];
        auto j = i - 1;

        while (j >= 0 && unsorted_value[j].first > key.first)
        {
            unsorted_value[j + 1] = unsorted_value[j];
            j--;
        }

        unsorted_value[j + 1] = key;
    }
}

static std::vector<int> sort_unique(std::vector<int>& unsorted_value)
{
    std::vector<int> res;

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


    for (int i = 0; i < unsorted_value.size(); i++)
        if (res.empty() || *res.rbegin() != unsorted_value[i])
            res.push_back(unsorted_value[i]);

    return res;
}

std::vector <int> get_covering_set(std::vector <Segment> segments)
{
    std::vector <int> result;

//    print(segments);

    sort_insertion(segments);

//    print(segments);

    auto point{-1};
    for (auto i = 0; i < segments.size() - 1; i++)
    {
        for (auto j = i + 1; j < segments.size(); j++)
            if (segments[i].second >= segments[j].first)
            {
                if (!result.empty() && segments[j].first <= *result.rbegin() &&
                    *result.rbegin() <= segments[j].second)
                    continue;
                else if (segments[i].second >= segments[j].second)
                    point = segments[j].second;
                else
                    point = segments[i].second;

            } else
                point = segments[i].second;

            if (!result.empty() && *result.rbegin() == point)
                continue;

            result.push_back(point);
    }

    if (segments.rbegin()->first > *result.rbegin())
        result.push_back(segments.rbegin()->second);


    return sort_unique(result);
}

int main(void)
{
    //-------------------------------------------------------------------------
    std::vector <Segment> segments = {{1, 2},
                                      {3, 4},
                                      {0, 5}};


    auto points = get_covering_set(std::move(segments));
    std::cout << points.size() << std::endl;
    for (auto point:points)
    {
        std::cout << point << " ";
    }
    std::cout << std::endl;

    assert(points.size() == 2);
    std::vector <int> res {2, 4};
    assert(points == res);

    //-------------------------------------------------------------------------
    segments = {{4, 7},
              {1, 3},
              {2, 5},
              {5, 6}};


    points = get_covering_set(std::move(segments));
    std::cout << points.size() << std::endl;
    for (auto point:points)
    {
        std::cout << point << " ";
    }
    std::cout << std::endl;

    cout << endl;
    //-------------------------------------------------------------------------
    segments = {{5, 6},
                {4, 7},
                {3, 8},
                {2, 9},
                {1,10}};

    assert(points.size() == 2);
    res = {3, 5};
    assert(points == res);

    points = get_covering_set(std::move(segments));
    std::cout << points.size() << std::endl;

    for (auto point:points)
    {
        std::cout << point << " ";
    }
    std::cout << std::endl;

    assert(points.size() == 1);
    assert(points == std::vector <int>{6});

    //-------------------------------------------------------------------------
    segments = {{1, 2},
                {2, 3},
                {3, 4},
                {4, 5},
                {5, 6} };


    points = get_covering_set(std::move(segments));
    std::cout << points.size() << std::endl;
    for (auto point:points)
    {
        std::cout << point << " ";
    }
    std::cout << std::endl;

    assert(points.size() == 3);
    res = {2, 4, 6};
    assert(points == res);

    //-------------------------------------------------------------------------
    segments = {{1, 2},
                {3, 4},
                {5, 6},
                {7, 8},
                {9, 10} };


    points = get_covering_set(std::move(segments));
    std::cout << points.size() << std::endl;
    for (auto point:points)
    {
        std::cout << point << " ";
    }
    std::cout << std::endl;

}