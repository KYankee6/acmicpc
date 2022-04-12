#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, K;

bool crange(int n)
{
    return n >= 0 && n <= 100000;
}

void bfs()
{
    vector<int> visited(100001, -1);
    queue<int> q;

    q.push(N);
    visited[N] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (visited[K] != -1)
        {
            cout << visited[K];
            return;
        }
        if (crange(cur + 1) && visited[cur + 1] > visited[cur] + 1 || visited[cur + 1] == -1)
        {
            visited[cur + 1] = visited[cur] + 1;
            q.push(cur + 1);
        }
        if (crange(cur - 1) && visited[cur - 1] > visited[cur] + 1 || visited[cur - 1] == -1)
        {
            visited[cur - 1] = visited[cur] + 1;
            q.push(cur - 1);
        }
        for (int i = cur; i <= 100000 && cur!=0; i *= 2)
        {

            if (crange(i) && visited[i] > visited[cur] || visited[i]==-1)
            {
                visited[i] = visited[cur];
                q.push(i);
            }
        }
    }
}

int main()
{
    cin >> N >> K;
    bfs();
    return 0;
}