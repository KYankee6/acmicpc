#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int l;
int dx[8] = {-2, -2, -1, -1, 2, 2, 1, 1};
int dy[8] = {-1, 1, -2, 2, -1, 1, -2, 2};

int bfs(vector<vector<int>> &graph, queue<pair<int, int>> &q)
{
    bool visited[302][302] = {};
    int max_val = 0;
    auto init = q.front();
    visited[init.first][init.second] = true;
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        if (cur.first >= 0 && cur.second >= 0 && cur.first < l && cur.second < l && graph[cur.first][cur.second] == -1)
            break;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int px = cur.first + dx[i];
            int py = cur.second + dy[i];

            if (px >= 0 && py >= 0 && px < l && py < l && !visited[px][py] && graph[px][py] == 0)
            {
                q.push({px, py});
                graph[px][py] = graph[cur.first][cur.second] + 1;
                max_val = max(max_val, graph[px][py]);
                visited[px][py] = true;
            }
            else if (px >= 0 && py >= 0 && px < l && py < l && !visited[px][py] && graph[px][py] == -1)
            {
                max_val = graph[cur.first][cur.second] + 1;
                return max_val;
            }
        }
    }
    return max_val;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int s1, s2;
        int d1, d2;
        cin >> l;
        cin >> s1 >> s2;
        cin >> d1 >> d2;

        vector<vector<int>> graph(l + 1, vector<int>(l + 1, 0)); // -> AC
        queue<pair<int, int>> q;
        graph[d1][d2] = -1;
        q.push({s1, s2});
        cout << bfs(graph, q) << "\n";
    }
    return 0;
}