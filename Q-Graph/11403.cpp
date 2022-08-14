#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<int>> graph(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> graph[i][j];
        }
    }
    for (int k = 0; k < N; k++)
    {
        for (int a = 0; a < N; a++)
        {
            for (int b = 0; b < N; b++)
            {
                if (graph[a][k] == 1 && graph[k][b] == 1)
                    graph[a][b] = 1;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}