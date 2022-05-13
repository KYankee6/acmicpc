// 2022-05-13 19:21:09
// acmicpc 1439
// 2022-05-13 19:30:01 AC

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    bool now = s[0] == '0' ? false : true;
    int zeros = s[0] == '0' ? 1 : 0;
    int ones = s[0] == '0' ? 0 : 1;
    for (int i = 1; i < s.size(); i++)
    {
        if (now == 0 && s[i] == '1')
        {
            now = !now;
            ones++;
        }
        else if (now == 1 && s[i] == '0')
        {
            now = !now;
            zeros++;
        }
    }
    cout<<min(zeros,ones);
    return 0;
}