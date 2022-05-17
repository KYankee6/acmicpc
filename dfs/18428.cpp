// https://www.acmicpc.net/problem/18428
// 감시 피하기
// 2022-05-18 02:42:35

// 아니 이코테 난이도 설정 수듄 실화 ?????
// dfs로 벽 설치
// X = 0 (빈칸)
// O = 1 (방해물)
// S = 2 (학생)
// T = 3 (선생) ->사실 얘는 좌표만 갖고 있으면 됨
// 2022-05-18 03:08:44 AC


#include <bits/stdc++.h>
using namespace std;

bool catched = true;
int N;
vector<vector<int>> graph;
deque<pair<int, int>> teach_pos;

/**
 * @brief check if we got students
 * 0->up, 1-> right, 2-> down, 3->left
 *
 * @return true if teacher catch student.
 * @return false if teach could not find student insight.
 */
bool teacher_beam(int x, int y)
{
    for (int i = x - 1; i >= 1; i--)
    {
        if (graph[i][y] == 1)
            break;
        if (graph[i][y] == 2)
            return true;
    }

    for (int i = y + 1; i <= N; i++)
    {
        if (graph[x][i] == 1)
            break;
        if (graph[x][i] == 2)
            return true;
    }
    for (int i = x + 1; i <= N; i++)
    {
        if (graph[i][y] == 1)
            break;
        if (graph[i][y] == 2)
            return true;
    }
    for (int i = y - 1; i >= 1; i--)
    {
        if (graph[x][i] == 1)
            break;
        if (graph[x][i] == 2)
            return true;
    }
    return false;
}

bool watch()
{
    if (!catched)
        return catched;
    for (auto pos : teach_pos)
    {
        int x = pos.first;
        int y = pos.second;
        if (teacher_beam(x, y))
            return true;
    }
    return false;
}

void wall(int depth, int x, int y)
{
    if (!catched)
        return;
    if (depth == 3)
    {
        catched = watch();
        return;
        // do something
    }
    for (int i = x; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            if (i == x && j == 0)
                j += y;
            if (graph[i][j] == 0)
            {
                graph[i][j] = 1;
                wall(depth + 1, i, j);
                graph[i][j] = 0;
            }
            if (!catched)
                return;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    graph.resize(N + 1, vector<int>(N + 1, 0));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            char c;
            cin >> c;
            switch (c)
            {
            case 'X':
            {
                graph[i][j] = 0;
                break;
            }
            case 'S':
            {
                graph[i][j] = 2;
                break;
            }
            case 'T':
            {
                graph[i][j] = 3;
                teach_pos.push_back({i, j});
                break;
            }
            }
        }
    }
    wall(0, 1, 1);
    if (!catched)
    {
        cout << "YES";
    }
    else
        cout << "NO";
    return 0;
}