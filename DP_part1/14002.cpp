#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    int dp[1001];
    cin >> N;
    fill(dp, dp + 1001, 0);
    vector<int> v(N, -1);
    stack<int> answer;
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
        dp[v[i]] = 1;
    }
    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[i] < v[j])
            {
                dp[v[j]] = max(dp[v[j]], dp[v[i]] + 1);
            }
        }
    }
    int cnt = *max_element(dp, dp + 1001);
    int init_top = max_element(dp, dp + 1001) - dp;

    answer.push(init_top);
    for (int i = init_top; i > 0; i--)
    {
        if (cnt == 0)
            break;
        if (dp[i] == 0)
            continue;
        int temp = dp[i];
        
    }

    cout << *max_element(dp, dp + 1001) << "\n";
    while (!answer.empty())
    {
        cout << answer.top() << " ";
        answer.pop();
    }
}
