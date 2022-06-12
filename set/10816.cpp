#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int answer = 0;
    map<string, int> m;
    int N, M;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        m[s]++;
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        string s;
        cin >> s;
        if (m.find(s) == m.end())
            cout << "0 ";
        else
            cout << m[s] << " ";
    }
}