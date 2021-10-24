#include <iostream>
#include <queue>
#include <list>
#include <algorithm>

//=============================================================================

using namespace std;

using FreqCharList = vector<pair<int, char>>;

//=============================================================================
FreqCharList calc_char_freq(string& str)
{
    FreqCharList res;

    for (int i = str.size() - 1; i > 0; i--)
    {
        if (i >= str.size())
            continue;

        int counter{0};
        char c = str[i];

        while (str.find(c) != string::npos)
        {
            int pos = str.find(c);

            if (pos != string::npos)
            {
                counter++;
                str.erase(str.begin() + pos);
            }
        }

        auto insert_pos = res.begin();

        for (auto it = res.begin(); it != res.end(); it++)
            if (it->first > counter)
            {
                insert_pos = it;
                break;
            }

        if (insert_pos == res.begin())
            res.push_back(make_pair(counter, c));
        else
            res.insert(insert_pos, make_pair(counter, c));

    }

    return res;
}
//=============================================================================
class HuffmanTree
{
public:
    char c;
    int freq;

    HuffmanTree* left;
    HuffmanTree* right;

    HuffmanTree(char c, int freq, HuffmanTree* left, HuffmanTree* right);
    ~HuffmanTree() = default;
};

//=============================================================================
HuffmanTree* build_tree(const FreqCharList& freq_char_list)
{
    
}

int main()
{
    string str("accepted");

    auto evaluated_str = calc_char_freq(str);

    return 0;
}
