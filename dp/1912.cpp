#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    long long dp[100001];
    long long answer = -1001;
    cin >> n;
    vector<int> v(n, 0);
    fill(dp, dp + 100001, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    answer = dp[0] = v[0];
    
    for (int i = 1; i < n; i++)
    {
        dp[i] = max(dp[i - 1] + v[i], (long long)v[i]);
        answer = max(dp[i], answer);
    }

    cout << answer;
}