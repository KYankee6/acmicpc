// 2022-09-25 22:55:31 로프.
// https://www.acmicpc.net/problem/2217

#include <bits/stdc++.h>
using namespace std;

int N;
bool cmp(const int &v1, const int &v2)
{
    return v1 > v2;
}

int get_weight_limit(int &pos, int &weight)
{
    return weight / (pos + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    vector<int> arr(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    int k = 0;
    int answer = arr[0];
    sort(arr.begin(), arr.end(), cmp);
    for (int i = 0; i < N; i++)
    {
        answer = max(answer, arr[i] * (i+1));
    }
    cout << answer;
    return 0;
}