// 2022-11-06 21:52:26
// https://www.acmicpc.net/problem/11656 접미사 배열

#include <bits/stdc++.h>
#define PLL pair<int, int>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;
    vector<string> answer;
    for (int i = 0; i < s.length(); i++)
    {
        string sub;
        for (int j = i; j < s.length(); j++)
        {
            sub += s[j];
        }
        answer.push_back(sub);
    }
    sort(answer.begin(), answer.end());
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << "\n";
    }
    return 0;
}