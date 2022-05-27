// https://www.acmicpc.net/problem/2352
// LIS Binary Search
// 2022-05-27 18:30:09

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> v(N, 0);
    vector<int> lis;
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    int i = 0, j = i + 1;
    lis.push_back(v[i]);
    while (j < N)
    {
        if (v[j] > lis[i])
        {
            lis.push_back(v[j]);
            i++;
        }
        else
        {
            auto it = lower_bound(lis.begin(), lis.end(), v[j]);
            *it = v[j];
        }
        j++;
    }
    cout << lis.size();
}