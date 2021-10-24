
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

void print(const std::vector<std::pair<int, int>>& vals)
{
    for (const auto v: vals)
        cout << v.first << " " << v.second << endl;

    cout << endl;
}

using Segment = std::pair<int, int>;

struct SegmentFlag
{
    SegmentFlag(const Segment& s, bool marked)
        :seg(s)
        ,is_marked(marked)
    {}
    Segment seg;
    bool is_marked{false};
};

static void sort_insertion(std::vector<Segment>& unsorted_value)
{
    for (int i = 1; i < unsorted_value.size(); i++)
    {
        auto key = unsorted_value[i];
        auto j = i - 1;

        while (j >= 0 && unsorted_value[j].second > key.second)
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

std::vector<SegmentFlag> fill(const std::vector <Segment>& segments)
{
    std::vector<SegmentFlag> res;

    for (const auto& seg: segments)
        res.push_back(SegmentFlag(seg, false));

    return res;
}

std::vector <int> get_covering_set(std::vector <Segment> segments)
{
    std::vector <int> result;

    sort_insertion(segments);

//    cout << endl;
//    print(segments);

    std::vector<SegmentFlag> segments_flag = fill(segments);

    for (auto i = 0; i < segments_flag.size() - 1; i++)
    {
        if (segments_flag[i].is_marked)
            continue;

        auto pnt = segments_flag[i].seg.second;

        if (segments_flag[i].seg.first == segments_flag[i].seg.second)
        {
            for (auto j = i + 1; j < segments_flag.size(); j++)
                if (!segments_flag[j].is_marked &&
                    (segments_flag[j].seg.first <= pnt && pnt <= segments_flag[j].seg.second))
                    segments_flag[j].is_marked = true;

            result.push_back(pnt);
            continue;
        }

        for (auto j = i + 1; j < segments_flag.size(); j++)
        {
            if (!segments_flag[j].is_marked &&
                (segments_flag[j].seg.first <= pnt && pnt <= segments_flag[j].seg.second))
                segments_flag[j].is_marked = true;
        }

        result.push_back(pnt);
    }

    if (!segments_flag.rbegin()->is_marked)
        result.push_back(segments_flag.rbegin()->seg.second);


    return sort_unique(result);
}

int main(void)
{
    std::vector <Segment> segments  {{4, 4},
    {5, 9},
    {0, 10},
    {2, 8},
    {12, 14},
    {0, 8},
    {3, 14},
    {5, 13},
    {4, 6}};

    auto points = get_covering_set(std::move(segments));
    std::cout << points.size() << std::endl;
    for (auto point:points)
    {
        std::cout << point << " ";
    }
    std::cout << std::endl;

    assert(points.size() == 3);
    std::vector <int> res {4, 9, 14};
    assert(points == res);

//    ( ответ: 3;  4 9 14)

    //-------------------------------------------------------------------------
     segments = {{1, 2},
                                      {3, 4},
                                      {0, 5}};


    points = get_covering_set(std::move(segments));
    std::cout << points.size() << std::endl;
    for (auto point:points)
    {
        std::cout << point << " ";
    }
    std::cout << std::endl;

    assert(points.size() == 2);
    res = {2, 4};
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

//    assert(points.size() == 2);
//    res = {3, 5};
//    assert(points == res);

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