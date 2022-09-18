// 2022-09-17 22:01:18
// https://www.acmicpc.net/problem/2293 동전1
// #include <bits/stdc++.h>
// using namespace std;

// int n, k;
// vector<int> coins;
// int answer;

// void dfs(int idx, int value)
// {
//     if (value == k)
//     {
//         answer++;
//         return;
//     }
//     if (value > k || idx>=n)
//         return;

//     dfs(idx, value + coins[idx]);
//     dfs(idx +1, value);
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     cin >> n >> k;
//     coins.resize(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> coins[i];
//     }
//     sort(coins.begin(), coins.end());
//     dfs(0, 0);
//     cout << answer;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> coins;
vector<int> dp;
int answer;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    coins.resize(n);
    dp.resize(k + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = coins[i]; j <= k; j++)
        {
            dp[j] = dp[j] + dp[j - coins[i]];
        }
    }

    cout << dp[k];
    return 0;
}