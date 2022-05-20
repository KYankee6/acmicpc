#include <bits/stdc++.h>
#define MAX 100000
using namespace std;

int main()
{
    vector<int> dp(MAX, -1);
    int N, K;
    cin >> N >> K;
    dp[N] = 0;
    if (N >= K)
    {
        cout << K - N;
    }
    else
    {
        for (int i = N; i < MAX / N; i *= 2)
        {
            dp[i] = 0;
        }
    }
    return 0;
}