#include <iostream>
#include <algorithm>
#include <vector>
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
    vector<int> pre(1001, -1);
    vector<int> answer;
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
        dp[i] = 1;
    }
    for (int i = 0; i <N; i++)
    {
        for (int j = i + 1; j <N; j++)
        {
            if (v[i] < v[j])
            {
                dp[j] = max(dp[j], dp[i] + 1);
                pre[j]=j;
            }
        }
    }
    int cur=max_element(dp, dp + 1001) - dp;
    answer.push_back(v[cur]);

    for(auto iter = cur-1; iter>=0;){
        if(dp[iter] == dp[cur]-1 && dp[cur]!=0){
            answer.push_back(v[iter]);
            cur = iter;
            iter = pre[iter];
        }
        else iter--;
    }
    reverse(answer.begin(), answer.end());

    cout<<*max_element(dp,dp+1001)<<"\n";
    for(auto e : answer){
        cout << e << " ";
    }
}
