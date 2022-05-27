// https://www.acmicpc.net/problem/18353
// 병사 배치하기
// 2022-05-27 16:55:48
// dp라는 것을 몰랐으면 조금 헤맸을것 같은데 일단 시작해봅시다.
// LIS 아닌가?

// 2022-05-27 17:49:19 답지보고 AC (시간이 없었다 ㅠㅠ)
// 단 이 문제의 경우 N^2 이 아니라 BS로 NlogN도 가능하다고 한다.
// 어떻께...?


#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v;

int main()
{
    int answer = 0;
    cin >> N;
    v.resize(N, 0);
    vector<int> dp(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < N; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (v[j] > v[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    cout << N - *max_element(dp.begin(),dp.end());
}