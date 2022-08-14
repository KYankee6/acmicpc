#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    int answer = 0x77777777;
    int idx = -1;
    cin >> N >> M;
    vector<vector<int>> graph(N, vector<int>(N, 0x00777766));

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    for (int i = 0; i < N; i++)
        graph[i][i] = 0;
    for (int k = 0; k < N; k++)
    {
        for (int a = 0; a < N; a++)
        {
            for (int b = 0; b < N; b++)
            {
                graph[a][b] = min(graph[a][b], graph[a][k] + graph[b][k]);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        int sum = accumulate(graph[i].begin(), graph[i].end(), 0) - max(0, graph[i][i]);
        if (answer > sum)
        {
            answer = sum;
            idx = i;
        }
    }
    cout << idx + 1;
    return 0;
}