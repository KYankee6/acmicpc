#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int S;

bool boundary_check(int cur)
{
    return cur >= 2 && cur <= 1000;
}

void bfs()
{
    vector<int> visited(1001);
    queue<int> q;
    fill(visited.begin(), visited.end(), 0);
    q.push(1);
    visited[1] = 1;
    int pre = 1;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        // copy and paste
        if (boundary_check(cur * 2) && visited[cur * 2] == 0)
        {
            if (cur * 2 == S)
            {
                cout << visited[cur]+1;
                return;
            }
            visited[cur * 2] = visited[cur] + 2;
            q.push(cur * 2);
        }
        if (boundary_check(cur - 1) && visited[cur - 1] == 0)
        {
            if (cur-1 == S)
            {
                cout << visited[cur];
                return;
            }
            visited[cur - 1] = visited[cur] + 1;
            q.push(cur - 1);
        }
        if (boundary_check(cur + pre) && visited[cur + pre] == 0)
        {
            if (cur + pre == S)
            {
                cout << visited[cur];
                return;
            }
            visited[cur + pre] = visited[cur] + 1;
            q.push(cur + pre);
        }
        pre = cur;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);

    cin >> S;
    bfs();
}