// https://programmers.co.kr/learn/courses/30/lessons/60059
// 2022-05-17 01:25:54
// bfs로 해보,,,고 싶,,,, 은데요
// 4방향 회전 + 왼위오아래
// cnt<자물쇠 홈의 개수 일때까지 이동
// cnt == 자물쇠 홈의 개수일때 회전 + cnt감소 안되도록 이동

// 함수 1번 회전
// 함수 2번 회전 + 남은 돌기수 리턴
// 아니 그럼 q에 지금 상태를 담아야 하나,,?
// 열쇠 돌기만 vector<pari<int,int>> 로 가지고 다니자.

// 2022-05-17 01:45:16 이것은 답지를 볼수밖에 없었따.
// 2022-05-17 02:26:28 AC
// 답지를 보면 겨우 1시간 걸리는데 이걸 시험시간에 1시간 안에 풀 수 있을까?
#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &v)
{
    vector<vector<int>> temp = v;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            v[j][(v.size()-1)-i] = temp[i][j];
        }
    }
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    bool answer = false;
    int M = key.size();
    int N = lock.size();
    int board_size = 2 * M + N;
    vector<vector<int>> board(board_size, vector<int>(board_size, 0));
    vector<vector<int>> go = key;
    for (int i = 0; i < lock.size(); i++)
    {
        for (int j = 0; j < lock.size(); j++)
        {
            board[i + M][j + M] = lock[i][j];
        }
    }
    for (int r = 0; r < 4; r++)
    {
        rotate(key);
        for (int q1 = 0; q1 < board.size() - M; q1++)
        {
            for (int q2 = 0; q2 < board.size() - M; q2++)
            {
                bool isFit = true;
                for (int i = 0; i < M; i++)
                {
                    for (int j = 0; j < M; j++)
                    {
                        board[i + q1][j + q2] += key[i][j];
                    }
                }
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < N; j++)
                    {
                        if (board[i + M][j + M] != 1)
                        {
                            isFit = false;
                        }
                    }
                }
                if (isFit)
                    return true;
                else
                {
                    for (int i = 0; i < M; i++)
                    {
                        for (int j = 0; j < M; j++)
                        {
                            board[i + q1][j + q2] -= key[i][j];
                        }
                    }
                }
            }
        }
    }

    return answer;
}
int main()
{
    vector<vector<int>> v1{{0, 0, 0}, {1, 0, 0}, {0, 1, 1}};
    vector<vector<int>> v2{{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    solution(v1, v2);
}