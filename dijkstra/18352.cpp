// 2022-05-14 00:55:06 bfs/dfs
// 다익스트라로 풀지 뭐..
// bfs로 풀까..?
// bfs 많이 했으니까 다익스트라로..
// 하기에 굳이..?
// 그래도 하자..

#include <bits/stdc++.h>
using namespace std;

int N, M, K, X;
vector<vector<int>> graph;
vector<int> dist;

void dijkstra(int start)
{
    priority_queue<pair<int, int>> pq; // cost, node
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty())
    {
        int cur_cost = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();
        if (dist[cur_node] < cur_cost || cur_cost > K)
            continue;
        for (int i = 0; i < graph[cur_node].size(); i++)
        {
            int next_node = graph[cur_node][i];
            if (dist[next_node] > dist[cur_node] + 1)
            {
                dist[next_node] = dist[cur_node] + 1;
                pq.push({-dist[next_node], next_node});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> K >> X;
    X--;
    graph.resize(N);
    dist.resize(N, INT_MAX);
    for (int i = 0; i < M; i++)
    {
        int src, dest;
        cin >> src >> dest;
        graph[src - 1].push_back(dest - 1);
    }
    dijkstra(X);
    bool is_present = false;
    for (int i = 0; i < N; i++)
    {
        if (dist[i] == K)
        {
            cout << i + 1<<"\n";
            is_present=true;
        }
    }
    if(!is_present)cout<<-1;
    return 0;
}