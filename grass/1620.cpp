#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, M;
    cin >> N >> M;

    map<string, int> dogam1;
    map<int, string> dogam2;
    for (int i = 0; i < N; i++)
    {
        string name;
        cin >> name;
        dogam1[name] = i + 1;
        dogam2[i + 1] = name;
    }
    for (int i = 0; i < M; i++)
    {
        string s;
        cin >> s;
        if (s[0] >= 'A')
        {
            cout << dogam1[s] << '\n';
        }
        else
        {
            int key = stoi(s);
            cout << dogam2[key] << "\n";
        }
    }
    return 0;
}