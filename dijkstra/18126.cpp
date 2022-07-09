#include <bits/stdc++.h>
#define INF 1e14
using namespace std;
typedef long long ll;

int N;
long long answer;
map<int, ll> dist;
map<int, bool> visited;
map<int, vector<pair<int, ll>>> graph;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        graph[A].push_back({B, C});
        graph[B].push_back({A, C});
        dist[A] = 0L;
        dist[B] = 0L;
    }

    priority_queue<pair<ll, int>> pq;
    pq.push({0, 1});
    visited[1] = true;
    while (!pq.empty())
    {
        auto node = pq.top().second;
        auto cost = pq.top().first;
        pq.pop();

        if (cost < dist[node])
            continue;
        for (auto e : graph[node])
        {
            auto nNode = e.first;
            auto nCost = e.second;
            if (dist[nNode] < nCost + cost && (visited.find(nNode) == visited.end() || !visited[nNode]))
            {
                dist[nNode] = cost + nCost;
                pq.push({dist[nNode], nNode});
                answer = max(answer, dist[nNode]);
                visited[nNode] = true;
            }
        }
    }
    cout << answer;
    return 0;
}