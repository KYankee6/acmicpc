// 2022-08-21 18:37:47
// 4485.cpp
// https://www.acmicpc.net/problem/4485
// BFS로 먼저 도전.

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

struct pos
{
    int cost;
    int x;
    int y;

    pos();
    pos(int _cost, int _x, int _y) : cost(_cost), x(_x), y(_y){};

    bool operator<(const pos &pos1) const
    {
        return cost > pos1.cost;
    }
};
int N;
vector<vector<int>> dist;
vector<vector<int>> graph;

bool in_range(int x, int y)
{
    return x >= 0 && y >= 0 && x < N && y < N;
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int bfs()
{
    priority_queue<pos> pq;
    pq.push(pos(graph[0][0], 0, 0));
    dist[0][0] = graph[0][0];
    while (!pq.empty())
    {
        auto cur_x = pq.top().x;
        auto cur_y = pq.top().y;
        auto cur_cost = pq.top().cost;

        pq.pop();
        if (cur_x == N - 1 && cur_y == N - 1)
        {
            return cur_cost;
        }
        if (cur_cost > dist[cur_x][cur_y])
            continue;
        for (int i = 0; i < 4; i++)
        {
            int px = cur_x + dx[i];
            int py = cur_y + dy[i];

            if (in_range(px, py) && dist[px][py] > cur_cost + graph[px][py])
            {
                dist[px][py] = cur_cost + graph[px][py];
                pq.push(pos(dist[px][py], px, py));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int cnt = 1;
    while (true)
    {

        cin >> N;
        if (N == 0)
            break;
        graph.resize(N, vector<int>(N, 0));
        dist.resize(N, vector<int>(N, INF));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> graph[i][j];
            }
        }

        cout << "Problem " << cnt++ << ": " << bfs()<<"\n";
        graph.clear();
        dist.clear();
    }

    return 0;
}