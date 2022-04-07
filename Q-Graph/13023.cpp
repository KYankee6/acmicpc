#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[1001];
int N, M;
vector<int> visited(1001, 0);

void dfs(int start, int& cnt)
{
    if (visited[start] != 0)
        return;
    visited[start] = cnt;
    N--;
    for (int i = 0; i < graph[start].size(); i++)
    {
        int next = graph[start][i];
        if (visited[next] == 0)
        {
            dfs(next, cnt);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    bool trav[1001];
    int cnt = 0;
    cin >> N >> M;
    fill(visited.begin(), visited.end(), 0);
    fill(trav, trav + 1001, false);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        trav[a] = true;
        trav[b] = true;
    }

    for (int i = 1; i < 1001; i++)
    {
        if (!trav[i] || visited[i] != 0)
            continue;
        dfs(i, ++cnt);
        N++;
    }
    cout<<N;
    return 0;
}