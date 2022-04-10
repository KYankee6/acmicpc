// 구현 생각한 시간 : 2~3분 (알고리즘 이미 명시됨)
// 생각든 것
// bfs로 순회하면서 dijkstra 1차원 배열 (시작점이 주어지고, 이 시작점에서만 구함)
// 1차원 배열 dijkstra[next] = min(dijkstra[node]+w[node], dijkstra[next]);
// bfs로 순회하면서 모두 업데이트
// 2022-04-08 00:50:24 코드 작성시작

// 2022-04-08 01:04:48 graph 인자로 넘길때 주소값 넘기는 건 맞는것 같은 데 복사하는 지 확인
// vector<int> graph[],
// vector<int>& graph,

// 2022-04-08 01:08:18 디버깅 시작

// 2022-04-08 01:21:45 다익스트라랑 bfs랑은 다르다는걸 깨달음,,,
// graph -> vector<pair<int,int>>로 map 따로 저장 x

// 2022-04-08 01:34:14 다익스트라 배열(list) 이용시 O(V^2) (그러므로 안될 듯? O(V)=20,000, V^2 = 4억, 제한 1초)
//                     우선 순위 큐 -> O(ElogV)
// 일단 둘다 구현 해보기로

// 2022-04-08 02:00:26 개같이 시간초과 ^^

// 2022-04-08 02:13:25 enchanced_dijkstra 작성 (사실상 거의 베껴버림)
// 둘 다 알아두면 좋겠지만 서도 그냥 힙쓰는 다익스트라가 좀더 나아보이긴 한다.
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

#define INF 1e9

using namespace std;

int V, E;
int start;
long long d[20001];
vector<pair<int, long long>> graph[20001];
vector<bool> visited;

void enchanced_dijkstra()
{
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    d[start]=0;
    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int v = graph[cur][i].first;
            int w = graph[cur][i].second;

            if (d[v] > d[cur] + w)
            {
                d[v] = d[cur] + w;
                pq.push({-d[v],v});
            }
        }
    }
}

int get_next_node()
{
    long long val = 1e9;
    int idx = 1;
    for (int i = 1; i <= V; i++)
    {
        if (d[i] < val && !visited[i])
        {
            val = d[i];
            idx = i;
        }
    }
    return idx;
}

void dijkstra()
{

    //초기 세팅
    d[start] = 0;
    visited[start] = true;
    for (int i = 0; i < graph[start].size(); i++)
    {
        d[graph[start][i].first] = graph[start][i].second;
    }

    for (int i = 0; i < V - 1; i++)
    {
        int cur = get_next_node();
        visited[cur] = true;
        for (int j = 0; j < graph[cur].size(); j++)
        {
            int v = graph[cur][j].first;
            int w = graph[cur][j].second;
            d[v] = min(d[v], d[cur] + w);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> V >> E >> start;

    fill(d, d + 20001, INF);
    visited.resize(V + 1, false);
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w}); // u -> first = node , second = weigth_utov
    }
    enchanced_dijkstra();
    for (int i = 1; i <= V; i++)
    {
        if (d[i] != INF)
            cout << d[i] << "\n";
        else
            cout << "INF\n";
    }
}