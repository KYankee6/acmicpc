// 2022-11-06 21:44:53
// https://www.acmicpc.net/problem/2822 점수계산

#include <bits/stdc++.h>
#define PLL pair<int, int>
using namespace std;

bool cmp(PLL &p1, PLL &p2)
{
    return p1.first > p2.first;
}

int main()
{
    int sum = 0;
    vector<PLL> v;
    vector<int> answer;
    for (int i = 0; i < 8; i++)
    {
        int num;
        cin >> num;
        v.push_back({num, i + 1});
    }
    sort(v.begin(), v.end(), greater<PLL>());
    for (int i = 0; i < 5; i++)
    {
        sum += v[i].first;
        answer.push_back(v[i].second);
    }
    cout << sum << "\n";
    sort(answer.begin(),answer.end());
    for (int i = 0; i < 5; i++)
    {
        cout<<answer[i]<<"\n";  
    }
    return 0;
}