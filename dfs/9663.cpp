// N - Queen 문제.
// 색종이 문제(17136)이랑 비슷한 방법으로 DFS 사용할 것 같다.
// 문제는 백트래킹인데. N이 15여서 가지치기를 좀 해야할것 같다.
// 퀸은 상하좌우 4대각선 모두 쭉쭉 뻗어나간다. 이걸 이용하면 좀 수월하지 않을까?
// x+=1, y+=2 dfs
// ㅇㅇ 그렇게 하면 될듯. 시간제한은 10초
// 2022-04-26 18:26:44 구현시작

// 2022-04-26 19:22:14 구현중 방문한 것들을 비트마스킹화 해야하지 않나 생각중.

#include <bits/stdc++.h>
#define in_range(x, y) (0 <= y && 0 <= x && x < N && y < N)
using namespace std;

int answer = 0;
int left = 0;
int N;
int half;
vector<vector<int>> graph;
vector<bool> row_exist;
vector<bool> col_exist;
vector<bool> diag1_exist;
vector<bool> diag2_exist;

bool all_checked()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (graph[i][j] != 1)
                return false;
        }
    }
    return true;
}

void uncheck(vector<pair<int, int>> &v)
{
    for (auto e : v)
    {
        graph[e.first][e.second] = 0;
    }
}

bool check(int x, int y)
{
    for (int i = 0; i < N; i++)
    {
        if (graph[x][i] == 1 || graph[i][y] == 1 || diag_exist[i])
        {
            return false;
        }
    }
    return true;
}

void dfs(int x, int depth)
{
    if (depth == 0)
    {
        answer++;
        return;
    }

    for (int i = x; i < N; i++)
    {
            if (!col_exist[i]])
            {
                row_exist[i] = true;
                col_exist[i] = true;

                dfs(i, j, depth - 1);
                row_exist[i] = false;
                col_exist[i] = false;
            }
    }
}
int main()
{
    cin >> N;
    half = N % 2 == 0 ? N / 2 : (N / 2) + 1;
    graph.resize(N, vector<int>(N, 0));
    row_exist.resize(N, false);
    col_exist.resize(N, false);
    diag1_exist.resize(N, false);
    diag2_exist.resize(N, false);
    if (N == 1)
    {
        cout << N;
        return 0;
    }

    dfs(0, 0, N);

    cout << answer;
    return 0;
}