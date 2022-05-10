// 2022-05-10 17:19:58 복붙함
// 2022-05-10 17:34:30 AC
// 돌아오는 조건을 확인 못해서 틀릴뻔
// 가는 것 모두 계산 -> O(V*ElogV)
//  V = 1,000 
//  E = 100,000
// logV ~= 15
// 대충 10^9 ~= 0.1초 ~ 1초

#include <bits/stdc++.h>
#define INF 1987654321
using namespace std;

int N, M;
int start, target;
vector<vector<pair<int, int>>> graph;
vector<int> dist;
vector<int> home_dist;

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

    cin >> N >> M >> target;
    target--;
    graph.resize(N);
    dist.resize(N, INF);
    int answer = INT_MIN;
    for (int i = 0; i < M; i++)
    {
        int src, dest, cost;
        cin >> src >> dest >> cost;
        graph[src - 1].push_back({dest - 1, cost});
    }
    start = target;
    dijkstra();
    for(int i=0; i<N; i++){
        home_dist.push_back(dist[i]);
    }
    for (int i = 0; i < N; i++)
    {
        int result=0;
        start = i;
        fill(dist.begin(),dist.end(),INF);
        dijkstra();
        result += dist[target]+home_dist[i];
        answer = max(result,answer);
    }
    cout << answer;
}