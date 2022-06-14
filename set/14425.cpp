#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int answer = 0;
    ;
    int N, M;
    cin >> N >> M;
    map<string, int> m;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        m[s] = 1;
    }
    for (int i = 0; i < M; i++)
    {
        string s;
        cin >> s;
        if (m.find(s) != m.end())
            answer++;
    }
    cout << answer;
    return 0;
    
}