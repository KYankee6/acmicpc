#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[2001];
int N, M;

bool dfs(int start, int depth, vector<bool> visited)
{
    visited[start] = true;
    if (depth == 5)
    {
        cout << "1";
        return true;
    }
    for (int i = 0; i < graph[start].size(); i++)
    {
        int next = graph[start][i];
        if (!visited[next])
        {
            if (dfs(next, depth + 1, visited))
            {
                return true;
            }
        }
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    bool trav[2001];
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        trav[a] = true;
        trav[b] = true;
    }
    for (int i = 0; i < 2001; i++)
    {
        if (!trav[i])
            continue;
        vector<bool> visited(2001, false);
        if (dfs(i, 1, visited))
            return 0;
    }
    cout << "0";
    return 0;
}