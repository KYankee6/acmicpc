#include <bits/stdc++.h>
using namespace std;

struct pos
{
    int x;
    int y;
    int cnt;
    pos(){};
    pos(int _x, int _y, int _cnt) : x(_x), y(_y), cnt(_cnt){};
};
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
int T;
int l;

bool in_range(int x, int y)
{
    return x >= 0 && y >= 0 && x < l && y < l;
}

int bfs(vector<vector<bool>> &visited, pos init, pos target)
{
    queue<pos> q;
    q.push(init);
    visited[init.x][init.y] = true;
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        q.pop();
        if (x == target.x && y == target.y)
        {
            return cnt;
        }
        for (int i = 0; i < 8; i++)
        {
            int px = x + dx[i];
            int py = y + dy[i];
            if (in_range(px, py) && !visited[px][py])
            {
                q.push({px, py, cnt + 1});
                visited[px][py] = true;
            }
        }
    }
    //thorws err
    return -1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    while (T--)
    {
        int x, y;
        int tx, ty;
        cin >> l;
        cin >> x >> y >> tx >> ty;
        vector<vector<bool>> visited(l, vector<bool>(l, false));
        cout << bfs(visited, {x, y, 0}, {tx, ty, 0}) << "\n";
    }
    return 0;
}