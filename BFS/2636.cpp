// 2022-09-04 15:29:54
// https://www.acmicpc.net/problem/2636
// 아하!
#include <bits/stdc++.h>
using namespace std;

int answer1;
int answer2;
int cnt;
vector<vector<int>> graph;
int N, M;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
void bfs()
{
    vector<pair<int, int>> gonner;
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    visited[0][0] = true;
    q.push({0, 0});
    while (!q.empty())
    {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int px = cur_x + dx[i];
            int py = cur_y + dy[i];
            if (px >= 0 && py >= 0 && px < N && py < M && !visited[px][py])
            {
                if (graph[px][py] == 0)
                {
                    q.push({px, py});
                }
                else
                {
                    gonner.push_back({px, py});
                }
                visited[px][py] = true;
            }
        }
    }
    for (int i = 0; i < gonner.size(); i++)
    {
        int x = gonner[i].first;
        int y = gonner[i].second;
        cnt--;
        graph[x][y] = 0;
    }

    answer1++;
    if (cnt != 0)
    {
        answer2 = cnt;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    graph.resize(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 1)
                cnt++;
        }
    }
    answer2=cnt;
    while (cnt != 0)
        bfs();
    cout << answer1 << "\n"
         << answer2;
}