// https://www.acmicpc.net/problem/14502
// 연구소
// 2022-05-17 18:31:39 시작
// 2022-05-17 18:45:17 디버그
// 2022-05-17 19:16:05 AC
// 45분이나 걸린게 아쉽지만, 시간도 많이 줄어들었고 메모리 사용량은 획기적으로 줄었다
// 점점 성장하는게 눈에 보여서 다행이다.
// 실수한 부분은 DFS 순회를 할때 for문에 인덱스를 잘못 넘긴 것이다.
// 그래서 while문으로 바꿨더니 시간이 더걸린다.
// for문으로 하자 for문으로..

#include <bits/stdc++.h>
using namespace std;

int answer = INT_MIN;
int N, M;
vector<vector<int>> graph;
queue<pair<int, int>> og_q;

int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

bool in_range(int x, int y)
{
    return x >= 0 && y >= 0 && x < N && y < M;
}
int bfs()
{
    int result = 0;
    queue<pair<int, int>> q = og_q;
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    vector<vector<int>> board = graph;
    while (!q.empty())
    {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        visited[cur_x][cur_y] = true;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int px = cur_x + dx[i];
            int py = cur_y + dy[i];
            if (in_range(px, py) && !visited[px][py] && board[px][py] == 0)
            {
                board[px][py] = 2;
                visited[px][py] = true;
                q.push({px, py});
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 0)
            {
                result++;
            }
        }
    }
    return result;
}

void wall(int depth, int x, int y)
{
    int i = x, j = y;
    if (depth == 3)
    {
        answer = max(bfs(), answer);
        return;
    }
    while (true)
    {
        i = i % N;
        j = j % M;
        if (graph[i][j] == 0)
        {
            graph[i][j]=1;
            wall(depth + 1, i, j + 1);
            graph[i][j]=0;
        }
        j++;
        if (i == N - 1 && j == M)
            break;
        if (j == M)
        {
            i++;
            j = 0;
        }
    }
    // for (int i = x; i < N; i++)
    // {
    //     for (int j = 0; j < M; j++)
    //     {
    //         if(j==0 && i==x)j+=y;
    //         if (graph[i][j] == 0)
    //         {
    //             graph[i][j] = 1;
    //             wall(depth + 1, i, j );
    //             graph[i][j] = 0;
    //         }
    //     }
    // }
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
            if (graph[i][j] == 2)
            {
                og_q.push({i, j});
            }
        }
    }
    wall(0, 0, 0);
    cout << answer;
}