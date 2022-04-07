#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> graph[2001];

int N, M;

bool compare(pair<int,int> t1, pair<int,int> t2)
{
    return t1.first==t2.first ? t1.first<t2.first : t1.second<t2.second;
}

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

    vector<pair<int, int>> temp;
    vector<int> trav;
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        temp.push_back({a, b});
    }
    sort(temp.begin(),temp.end(),compare);
    for (int i = 0; i < temp.size(); i++)
    {
        int a = temp[i].first;
        int b = temp[i].second;
        graph[a].push_back(b);
        graph[b].push_back(a);
        trav.push_back(a);
    }
    for (int i = 0; i < trav.size(); i++)
    {
        vector<bool> visited(N, false);
        if (dfs(trav[i], 1, visited))
            return 0;
    }
    cout << "0";
    return 0;
}