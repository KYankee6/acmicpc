// https://www.acmicpc.net/problem/14888
// 연산자 끼워넣기
// 2022-05-18 02:08:13
// 2022-05-18 02:40:04 30분 만에 푸는 문제였는데
// 간단한 조합인줄 알았으나 중복조합이었음.

#include <bits/stdc++.h>
using namespace std;
int ans_min = INT_MAX;
int ans_max = INT_MIN;
int N;
vector<int> numbers;
vector<int> ops_cnt;
vector<bool> visited;

int cal_ops(int idx, int oidx, int result)
{
    switch (oidx)
    {
    case 0:
    {
        result += numbers[idx];
        break;
    }
    case 1:
    {
        result -= numbers[idx];
        break;
    }
    case 2:
    {
        result *= numbers[idx];
        break;
    }
    case 3:
    {
        result /= numbers[idx];
        break;
    }
    }
    return result;
}



void dup_comb(int depth, int idx, int oidx, int result)
{
    if (depth == N-1)
    { // N-1개의 연산을 채웠다면,
        ans_min = min(ans_min, result);
        ans_max = max(ans_max, result);
        return;
    }

    for (int j = 0; j < 4; j++)
    {
        if (!visited[idx] && ops_cnt[j] > 0)
        {
            visited[idx] = true;
            ops_cnt[j]--;
            int prev_result = result;
            result = cal_ops(idx+1, j, result);
            dup_comb(depth+1,idx + 1, j, result);
            result = prev_result;
            visited[idx] = false;
            ops_cnt[j]++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;

    numbers.resize(N, 0);
    ops_cnt.resize(4, 0);
    visited.resize(N - 1, false);
    for (int i = 0; i < N; i++)
    {
        cin >> numbers[i];
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> ops_cnt[i];
    }
    dup_comb(0,0,0,numbers[0]);
    cout<<ans_max<<"\n";
    cout<<ans_min;
}