// 2022-04-19 19:00:50 문제 풀이 시작
// bfs로 dx, dy 정해줘서 꺾어주면 되는데, dir 사용해야 할듯
// rotate()함수를 사용하는게 어떤지 고민중 -> 필요없다. 나머지 2개만 return하는 식으로 가야겠다.
// 방법의 '개수' 를 구하는 문제이다. 쉣, visited 숫자를 점점 늘려야할수도 있겠다.
// 그리고 대각선으로 꺾을때는 (0,1) (1,1), (1,0) 도 확인해야한다.

// 2022-04-19 19:04:20 구현 시작
// 2022-04-19 19:47:23 구현 끝
// 중간에 visited 벡터를 조금 변형 시켜서 비트마스크화 시킴.
// 2022-04-19 21:50:45 아니 이걸 못푸네
// 비트마스크와는 개뻘짓이었음

// 2022-04-19 22:16:08 "마지막이 막혀있는 경우가 없다고 한적 없습니다"
// 마지막이 막혀있으면 탐색하면 time over 납니다... 왜?

#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> graph;
int N;
// 1 -> 가로
// 2 -> 대각선
// 3 -> 세로

int dx[3] = {-1, 0, 0};
int dy[3] = {0, 0, -1};

vector<tuple<int, int, int>> get_next_pipes(tuple<int, int, int> cur)
{
    vector<tuple<int, int, int>> next_pipe;
    int cur_x = get<0>(cur);
    int cur_y = get<1>(cur);
    int cur_dir = get<2>(cur);
    if (cur_dir == 1)
    {
        next_pipe.push_back(make_tuple(cur_x, cur_y + 1, cur_dir));
        next_pipe.push_back(make_tuple(cur_x + 1, cur_y + 1, cur_dir + 1));
    }
    if (cur_dir == 2)
    {
        next_pipe.push_back(make_tuple(cur_x, cur_y + 1, cur_dir - 1));
        next_pipe.push_back(make_tuple(cur_x + 1, cur_y + 1, cur_dir));
        next_pipe.push_back(make_tuple(cur_x + 1, cur_y, cur_dir + 1));
    }
    if (cur_dir == 3)
    {
        next_pipe.push_back(make_tuple(cur_x + 1, cur_y, cur_dir));
        next_pipe.push_back(make_tuple(cur_x + 1, cur_y + 1, cur_dir - 1));
    }
    return next_pipe;
}
bool is_in_range(int x, int y)
{
    return x >= 0 && y >= 0 && x < N && y < N;
}

bool is_not_in_range(int x, int y)
{
    return !(x >= 0 && y >= 0 && x < N && y < N);
}
bool check_visit_with_dir(int v, int cur_d)
{
    return v & (1 << cur_d);
}

void bfs()
{
    queue<tuple<int, int, int>> q;
    int answer = 0;
    q.push({0, 1, 1});

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        vector<tuple<int, int, int>> next_pipes = get_next_pipes(cur);
        for (int i = 0; i < next_pipes.size(); i++)
        {
            auto next = next_pipes[i];
            int next_x = get<0>(next);
            int next_y = get<1>(next);
            unsigned short next_dir = get<2>(next);
            if (!is_in_range(next_x, next_y))
                continue;
            if (next_dir == 2)
            {
                if (next_x == N - 1 && next_y == N - 1 && graph[next_x][next_y] != 1)
                {
                    bool is_no_wall = true;
                    for (int j = 0; j < 3; j++)
                    {
                        int px = next_x + dx[j];
                        int py = next_y + dy[j];
                        if (graph[px][py] == 1)
                        {
                            is_no_wall = false;
                            break;
                        }
                    }
                    if (is_no_wall)
                        answer++;
                }
                else
                {
                    bool is_no_wall = true;
                    for (int j = 0; j < 3; j++)
                    {
                        int px = next_x + dx[j];
                        int py = next_y + dy[j];
                        if (graph[px][py] == 1)
                        {
                            is_no_wall = false;
                            break;
                        }
                    }
                    if (is_no_wall)
                    {
                        q.push({next_x, next_y, next_dir});
                    }
                }
            }
            else
            {
                if (next_x == N - 1 && next_y == N - 1 && graph[next_x][next_y] != 1)
                {
                    answer++;
                }
                else if (graph[next_x][next_y] != 1)
                {
                    q.push({next_x, next_y, next_dir});
                }
            }
        }
    }
    cout << answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    graph.resize(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> graph[i][j];
        }
    }
    if (graph[N - 1][N - 1] == 1)
    {
        cout << 0;
        return 0;
    }
    bfs();
    return 0;
}