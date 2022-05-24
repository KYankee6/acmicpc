// https://www.acmicpc.net/problem/1932
// 2022-05-24 20:13:47
// 정수삼각형

// 2022-05-24 20:32:03 AC
#include <bits/stdc++.h>
using namespace std;

int N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    vector<vector<int>> tri(N, vector<int>(N, -1));
    vector<vector<int>> dp(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> tri[i][j];
        }
    }
    dp[0][0] = tri[0][0];
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + tri[i][j]);
            }
            else if (j == i)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + tri[i][j]);
            }
            else
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + tri[i][j]);
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + tri[i][j]);
            }
        }
    }
    cout << *max_element(dp[N - 1].begin(), dp[N - 1].end());
}