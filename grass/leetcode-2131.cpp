#include <bits/stdc++.h>
using namespace std;

int longestPalindrome(vector<string> &words)
{
    int same_cnt = 0;
    int answer = 0;
    vector<vector<int>> hmap(27, vector<int>(27, 0));
    for (int i = 0; i < words.size(); i++)
    {
        string str = words[i];
        if (hmap[str[1] - 'a'][str[0] - 'a'] > 0)
        {
            hmap[str[1] - 'a'][str[0] - 'a']--;
            answer += 4;
        }
        else if (str[0] == str[1])
        {
            hmap[str[1] - 'a'][str[0] - 'a']++;
        }
        else
        {
            hmap[str[0] - 'a'][str[1] - 'a']++;
        }
    }
    for (int i = 0; i < hmap.size(); i++)
    {
        if (hmap[i][i] > 0)
        {
            answer += 2;
            break;
        }
    }
    return answer;
}

int main()
{
    vector<string> v = {
        "lc",
        "cl",
        "gg"
    };
    cout<<longestPalindrome(v)<<endl;;
}