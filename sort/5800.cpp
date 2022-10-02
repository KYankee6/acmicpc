// 2022-10-02 19:34:20
// https://www.acmicpc.net/problem/5800

#include <bits/stdc++.h>
using namespace std;

int N;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    int arr[100][51];
    for (int i = 0; i < N; i++)
    {
        int max_val = INT_MIN, min_val = INT_MAX, lgap = INT_MIN;
        int e;
        cin >> e;
        for (int j = 0; j < e; j++)
        {
            cin >> arr[i][j];
        }
        sort(arr[i], arr[i] + e, greater<int>());
        max_val = max(max_val, arr[i][0]);
        min_val = min(min_val, arr[i][0]);
        lgap = max(lgap, abs(arr[i][0] - arr[i][1]));
        for (int j = 1; j < e; j++)
        {
            max_val = max(max_val, arr[i][j]);
            min_val = min(min_val, arr[i][j]);
            lgap = max(lgap, abs(arr[i][j - 1] - arr[i][j]));
        }
        cout << "Class " << i + 1 << "\n";
        cout << "Max " << max_val<<", ";
        cout << "Min " << min_val<<", ";
        cout << "Largest gap " << lgap<<"\n";
    }
    return 0;
}