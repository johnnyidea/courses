#include <iostream>
#include <map>

//=============================================================================

using namespace std;

//=============================================================================
int main()
{
    int letters_num{0};
    int bits_num{0};

    cin >> letters_num;
    cin >> bits_num;

    map<char, string> letters_code;
    for (int i = 0; i < letters_num; i++)
    {
        string str;
        char letter, dummy;
        cin >> letter >> dummy;
        cin >> str;
        letters_code.emplace(letter, str);
    }

    string code;
    cin >> code;

    string res;

    while (!code.empty())
        for (const auto& letter_code: letters_code)
        {
            int pos = code.find(letter_code.second);
            if (pos == 0)
            {
                res.push_back(letter_code.first);
                code.erase(0, letter_code.second.size());
                break;
            }
        }

    cout << res;

    return 0;
}
//=============================================================================