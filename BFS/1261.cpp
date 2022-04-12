#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M;
vector<vector<int>> graph(101, vector<int>(101, -1));
vector<vector<int>> board(101, vector<int>(101, 101 * 101));

bool cond_range(int px, int py)
{
    return px >= 0 && py >= 0 && px < N && py < M;
}

void bfs()
{
    queue<pair<int, int>> q;
    int answer = 0;
    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < M; j++)
        {
            graph[i][j] = (int)(temp[j] - '0');
        }
    }
    q.push({0, 0});
    board[0][0] = 0;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int px = cur.first + dx[i];
            int py = cur.second + dy[i];

            if (cond_range(px, py) && graph[px][py] == 0 && (board[px][py] > board[cur.first][cur.second] || board[px][py] == 101 * 101))
            {
                q.push({px, py});
                board[px][py] = min(board[px][py], board[cur.first][cur.second]);
            }
            if (cond_range(px, py) && graph[px][py] == 1 && (board[px][py] > board[cur.first][cur.second] + 1 || board[px][py] == 101 * 101))
            {
                q.push({px, py});
                board[px][py] = min(board[cur.first][cur.second] + 1, board[px][py]);
            }
        }
    }
}

int main()
{
    cin >> M >> N;
    bfs();
    cout << board[N - 1][M - 1];
    return 0;
}

// void break_bfs()
// {
//     vector<vector<int>> search(101, vector<int>(101, 101 * 101));
//     queue<pair<int, int>> q;
//     int answer = 0;
//     q.push({0, 0});
//     search[0][0] = 0;
//     while (!q.empty())
//     {
//         auto cur = q.front();
//         q.pop();
//         if (cur.first == N - 1 && cur.second == M - 1)
//         {
//             cout << search[N - 1][M - 1];
//             return ;
//         }
//         for (int i = 0; i < 4; i++)
//         {
//             int px = cur.first + dx[i];
//             int py = cur.second + dy[i];

//             if (cond_range(px, py) && graph[px][py] == 0 && (search[px][py] > search[cur.first][cur.second] || search[px][py] == 101 * 101))
//             {
//                 q.push({px, py});
//                 search[px][py] = min(search[px][py], search[cur.first][cur.second]);
//                 answer = search[px][py];
//             }
//             if (cond_range(px, py) && graph[px][py] == 1 && (search[px][py] > search[cur.first][cur.second] + 1 || search[px][py] == 101 * 101))
//             {
//                 q.push({px, py});
//                 search[px][py] = min(search[cur.first][cur.second] + 1, search[px][py]);
//                 answer = search[px][py];
//             }
//         }
//     }
// }