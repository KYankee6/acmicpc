#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    int cnt = 0;
    int answer = N + M;
    vector<bool> v(100000001, false);
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        v[num] = true;
    }
    for (int i = 0; i < M; i++)
    {
        int num;
        cin >> num;
        if (v[num])
            cnt++;
    }
    cout << answer - (2 * cnt);
    return 0;
}