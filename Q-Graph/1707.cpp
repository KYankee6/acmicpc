#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool bfs(int init, vector<bool> &visited, vector<int> graph[])
{
    int bip[20001];
    fill(bip, bip + 20001, -1);
    bool team = false;
    queue<int> q;
    q.push(init);
    visited[init] = true;
    bip[init] = team;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        team = bip[node];
        for (int i = 0; i < graph[node].size(); i++)
        {
            int next = graph[node][i];
            if (bip[next] != -1 && bip[next] == team)
                return false;
            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
                bip[next] = !team;
            }
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int K;
    cin >> K;
    while (K--)
    {
        vector<int> graph[20001];

        vector<bool> visited;
        bool result = true;
        int V, E;
        cin >> V >> E;
        visited.resize(V + 1, false);
        for (int i = 0; i < E; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for (int i = 1; i <= V; i++)
        {
            if (!visited[i] && !bfs(i, visited, graph))
            {
                result = false;
                break;
            }
        }
        if (result)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}