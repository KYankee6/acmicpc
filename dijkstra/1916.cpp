// 2022-05-10 16:34:20
// 다익스트라 문제풀이 연습

// 2022-05-10 16:40:01 구현 완료
// 2022-05-10 16:44:32 시간 초과
// 1 <= V <= 1,000, 1 <= M <= 100,000
// O(E*logV)여서 터질일이 없어야 정상인데..?
// 친구야 C++의 priority_queue는 맥스 힙이란다?
// 맥스 힙은 큰 수부터 정렬을 한단다?
// 알고있었다고? ?  ? ?? ? ? ? ? ? ?  ?  ?  ?  ?  ? 
// 2022-05-10 17:16:36 AC, 실수하지말자

#include <bits/stdc++.h>
#define INF 1987654321
using namespace std;

int N, M;
int start, target;
vector<vector<pair<int, int>>> graph;
vector<int> dist;

void dijkstra()
{
    priority_queue<pair<int, int>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty())
    {
        int cur_cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (dist[cur] < cur_cost)
            continue;
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i].first;
            int cost = graph[cur][i].second;
            if (dist[next] > dist[cur] + cost)
            {
                dist[next] = dist[cur] + cost;
                pq.push({-dist[next], next});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    graph.resize(N);
    dist.resize(N, INF);
    for (int i = 0; i < M; i++)
    {
        int src, dest, cost;
        cin >> src >> dest >> cost;
        graph[src - 1].push_back({dest - 1, cost});
    }
    cin >> start >> target;
    start--;
    target--;
    dijkstra();
    cout << dist[target];
}