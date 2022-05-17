// https://www.acmicpc.net/problem/18405
// 경쟁적 전염
// 2022-05-17 19:43:14
// 2022-05-17 19:56:13 AC
// 4초를 줄이는 기염을 보여줌
// 확실히 코드 라인수도 줄어들고 ->늘어났음;; 가독성도 올라감
// struct를 쓰는 습관을 들여야 겠다.

#include <bits/stdc++.h>

using namespace std;

struct obj
{
    int x;
    int y;
    int t;
    obj(){};
    obj(int _x, int _y, int _t) : x(_x), y(_y), t(_t){};
};

int N, K, S, X, Y;
vector<vector<int>> graph;
deque<obj> virus;

bool cmp(obj &o1, obj &o2)
{
    return o1.t < o2.t;
}

bool in_range(int x, int y)
{
    return x >= 1 && y >= 1 && x <= N && y <= N;
}

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bfs()
{
    int loop = virus.size();
    while (loop--)
    {
        int cur_x = virus[0].x;
        int cur_y = virus[0].y;
        int cur_t = virus[0].t;
        virus.pop_front();
        for (int i = 0; i < 4; i++)
        {
            int px = cur_x + dx[i];
            int py = cur_y + dy[i];
            if (in_range(px, py) && graph[px][py] == 0)
            {
                graph[px][py] = cur_t;
                virus.push_back(obj(px, py, cur_t));
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cur_time = 0;
    cin >> N >> K;
    graph.resize(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] != 0)
            {
                virus.push_back(obj(i, j, graph[i][j]));
            }
        }
    }
    cin >> S >> X >> Y;
    sort(virus.begin(), virus.end(), cmp);
    while (cur_time < S)
    {
        bfs();
        cur_time++;
    }
    cout << graph[X][Y];
    return 0;
}