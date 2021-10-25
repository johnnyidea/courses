#include <iostream>
#include <queue>
#include <list>
#include <algorithm>
#include <map>

//=============================================================================

using namespace std;

using FreqCharList = vector<pair<int, char>>;

//=============================================================================
FreqCharList calc_char_freq(string str)
{
    FreqCharList res;

    if (str.size() == 1)
        return {{1, str[0]}};

    int i = str.size() - 1;
    while (!str.empty())
    {
        while (i >= str.size())
            i--;

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

        i--;
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

    HuffmanTree(char c_, int freq_, HuffmanTree* left_ = nullptr, HuffmanTree* right_ = nullptr)
    {
        c = c_;
        freq = freq_;
        left = left_;
        right = right_;
    }

    ~HuffmanTree() = default;
};
//=============================================================================
HuffmanTree* build_tree(const FreqCharList& freq_char_list)
{
    auto comp_freq = [&](HuffmanTree* left, HuffmanTree* right)
    {
        return left->freq > right->freq;
    };

    priority_queue<HuffmanTree*, vector<HuffmanTree*>, decltype(comp_freq)> three(comp_freq);

    for (const auto& f_c: freq_char_list)
    {
        HuffmanTree* new_node = new HuffmanTree(f_c.second, f_c.first);
        three.push(new_node);
    }

    HuffmanTree * root;

    while (three.size() > 1)
    {
        auto* l = three.top();
        three.pop();
        auto* r = three.top();
        three.pop();

        auto* new_node = new HuffmanTree(' ', l->freq + r->freq, l, r);

        three.push(new_node);
    }

    root = three.top();

    return root;
}
//=============================================================================
string char_code(": ");

void assign_letter_to_code(HuffmanTree *huffman_tree, vector<string>& codes)
{
    if (huffman_tree)
    {
        if (huffman_tree->left)
            char_code += "0";

        assign_letter_to_code(huffman_tree->left, codes);

        if (huffman_tree->right)
            char_code += "1";

        assign_letter_to_code(huffman_tree->right, codes);

        if (!huffman_tree->left && !huffman_tree->right)
        {
            if (char_code.size() == 2)
                char_code += "0";

            char_code.insert(char_code.begin(), huffman_tree->c);
            codes.push_back(char_code);
            char_code.pop_back();
            char_code.erase(0, 1);
        }
        if (huffman_tree->left && huffman_tree->right)
            char_code.pop_back();
    }
}
//=============================================================================
void print_info(vector<string>& codes, const string& str)
{
    string code;
    map<char, string> code_map;
    for (const auto& letter_code: codes)
        code_map.emplace(letter_code[0], letter_code.substr(letter_code.find(": ") + 2));

    for (const auto& c:str)
        code.append(code_map[c]);

    cout << codes.size() << " " << code.size() << endl;

    for (const auto& letter_code: codes)
        cout << letter_code << endl;

    cout << code << endl;
}
//=============================================================================

//=============================================================================
int main()
{
    string str;
    cin >> str;

    auto evaluated_str = calc_char_freq(str);

    auto* huffman_three = build_tree(evaluated_str);
    vector<string> codes;
    codes.reserve(evaluated_str.size());

    assign_letter_to_code(huffman_three, codes);

    print_info(codes, str);

    return 0;
}
//=============================================================================