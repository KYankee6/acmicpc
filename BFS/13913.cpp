#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, K;
vector<int> answer;

void bfs()
{
    vector<int> visited(100001);
    vector<int> pre(100001); // first pre, second cnt;
    queue<int> q;
    fill(visited.begin(), visited.end(), 0);
    q.push(N);
    visited[N] = true;
    pre[N]=N;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        int next_arr[4] = {cur + 1, cur - 1, cur * 2};
        for (int i = 0; i < 3; i++)
        {
            int next = next_arr[i];
            if (next >= 0 && next <= 100000 && (visited[next] > visited[cur] + 1 || visited[next]==0))
            {
                q.push(next);
                visited[next] = visited[cur] + 1;
                pre[next] = cur;
            }
            if (next >= 0 && next <= 100000 && next == K)
            {
                int trav = next;
                int cnt = 0;
                while (trav != N)
                {
                    answer.push_back(trav);
                    trav = pre[trav];
                    cnt++;
                }
                cout << cnt << "\n";
                answer.push_back(N);
                reverse(answer.begin(), answer.end());
                for (auto e : answer)
                {
                    cout << e << " ";
                }
                return;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);

    cin >> N >> K;
    if (N == K)
    {
        cout << "0\n"<<N;
    }
    else
    {
        bfs();
    }
}