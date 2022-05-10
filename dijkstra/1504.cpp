// 2022-05-10 17:38:43 복붙 하지 않고 풀기.
// 먼저 그냥 dijsktra 때리기
// 그 이후 두 정점중 dist[v] 값이 작은 놈으로 고른 후 다시 N까지 다익스트라
// 혹은 두개 다익스트라 때려보기

// 2022-05-10 18:10:03 까다롭네용
//  2022-05-11 01:26:02 접근 법은 맞았는데 구현에서 좀 삽질했따.
// 특히 INF 값 설정이 힘들었다..
// 987654321로 하면 NAC
// 8~1로 하면 ac
#include <bits/stdc++.h>
#define INF 87654321
using namespace std;

int answer = INF;
int V, E;
int mv1, mv2;
vector<vector<pair<int, int>>> graph;
vector<int> dist;

void dijkstra(int start)
{
    priority_queue<pair<int, int>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty())
    {
        int cCost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (dist[cur] < cCost)
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

    cin >> V >> E;
    graph.resize(V);
    dist.resize(V, INF);
    for (int i = 0; i < E; i++)
    {
        int src, dest, cost;
        cin >> src >> dest >> cost;
        src--;
        dest--;
        graph[src].push_back({dest, cost});
        graph[dest].push_back({src, cost});
    }
    cin >> mv1 >> mv2;
    mv1--;
    mv2--;
    dijkstra(0);
    int answer1 = 0;
    int answer2 = 0;
    int answer3 = 0;
    int answer4 = 0;


    // 0 -> mv1 -> mv2 -> N
    int zero_to_mv1_cost = dist[mv1];

    // 0 -> mv2 -> mv1 -> N
    int zero_to_mv2_cost = dist[mv2];

    fill(dist.begin(), dist.end(), INF);
    dijkstra(mv1);
    int mv12_cost = dist[mv2];
    int mv1_end_cost = dist[V-1];

    fill(dist.begin(), dist.end(), INF);
    dijkstra(mv2);
    int mv21_cost = dist[mv1];
    int mv2_end_cost = dist[V-1];

    answer1 += zero_to_mv1_cost + mv12_cost + mv2_end_cost;
    answer2 += zero_to_mv2_cost + mv21_cost + mv1_end_cost;
    answer = min(answer1,answer2);
    if (answer >= INF)
        cout << -1;
    else
        cout << answer;
    return 0;
}