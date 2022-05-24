// https://www.acmicpc.net/problem/11052
// 카드 구매하기
// 2022-05-20 13:39:08
// DP

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    vector<int> v;
    vector<int> dp;
    v.resize(N + 1, 0);
    dp.resize(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        cin >> v[i];
        dp[i] = v[i];
    }
    dp[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j < i; j++)
        {
            dp[i] = max(dp[i], dp[i-j] + dp[j]);
        }
    }
    cout << dp[N];
}