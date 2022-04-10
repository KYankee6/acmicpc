#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int M, N;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool visited[1002][1002] = {};
int blank_cnt = 0;
int max_val = -1;

void bfs(vector<vector<int>> &graph, queue<pair<int, int>> &q)
{
    auto init = q.front();
    visited[init.first][init.second] = true;
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int px = cur.first + dx[i];
            int py = cur.second + dy[i];
            if (px >= 0 && py >= 0 && px < M && py < N && !visited[px][py] && graph[px][py] == 0)
            {
                q.push({px, py});
                graph[px][py] = graph[cur.first][cur.second] + 1;
                max_val = max(max_val, graph[px][py]);
                visited[px][py] = true;
                blank_cnt--;
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
    // vector<vector<int>> graph(1024, vector<int>(1024, 0)); -> stack overflow 
    vector<vector<int>> graph(M, vector<int>(N, 0)); // -> AC
    queue<pair<int, int>> q;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 1)
            {
                q.push({i, j});
            }
            if (graph[i][j] == 0)
            {
                blank_cnt++;
            }
        }
    }
    if (blank_cnt == 0)
    {
        cout << "0";
    }

    else
    {
        bfs(graph, q);

        if (blank_cnt != 0)
        {
            cout << "-1";
        }
        else
        {
            cout << max_val - 1;
        }
    }
    return 0;
}