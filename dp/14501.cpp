// 2022-05-25 18:21:49
// https://www.acmicpc.net/problem/14501
// 퇴사

// 2022-05-25 18:47:06 AC
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> v;
    vector<int> dp(21, 0);
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    for (int i = 0; i < N+1; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int sum = dp[j];
            int walker = j;
            while (true)
            {
                if (walker >= i)
                    break;
                if (walker + v[walker].first > i)
                {
                    walker++;
                    continue;
                }
                else
                {
                    sum += v[walker].second;    
                    walker += v[walker].first;
                }
            }
            dp[i] = max(dp[i], sum);
        }
    }
    cout << dp[N];
    return 0;
}
