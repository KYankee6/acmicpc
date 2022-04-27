// N - Queen 문제.
// 색종이 문제(17136)이랑 비슷한 방법으로 DFS 사용할 것 같다.
// 문제는 백트래킹인데. N이 15여서 가지치기를 좀 해야할것 같다.
// 퀸은 상하좌우 4대각선 모두 쭉쭉 뻗어나간다. 이걸 이용하면 좀 수월하지 않을까?
// x+=1, y+=2 dfs
// ㅇㅇ 그렇게 하면 될듯. 시간제한은 10초
// 2022-04-26 18:26:44 구현시작

// 2022-04-26 19:22:14 구현중 방문한 것들을 비트마스킹화 해야하지 않나 생각중.

// 첫번째 실패 시도
// graph를 방문했는지(Left)와 순회하며, 방문한 곳이면 방문하지 않으며 순회 -> 시간초과
// -> 퀸이 어디있는지, 퀸이 있으면 안되는 곳까지 저장

// 두번째 실패 시도
// graph를 순회하며 퀸 위치만 저장.
// 다음 순회시, 퀸이 이전 퀸을 공격할 수 있는 위치에 있는지 확인 -> 시간초과

// 2022-04-27 00:41:12 세번째 시도
// 해답법 보고 시도중
#include <bits/stdc++.h>
#define in_range(x, y) (0 <= y && 0 <= x && x < N && y < N)
using namespace std;

int answer = 0;
int left = 0;
int N;
int half;
vector<vector<int>> graph;
vector<int> col;

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

// void uncheck(vector<pair<int, int>> &v)
// {
//     for (auto e : v)
//     {
//         graph[e.first][e.second] = 0;
//     }
// }

// bool check(int x, int y)
// {
//     for (int i = 0; i < N; i++)
//     {
//         if (graph[x][i] == 1 || graph[i][y] == 1 || diag_exist[i])
//         {
//             return false;
//         }
//     }
//     return true;
// }
bool check(int level)
{
    for(int i = 0; i < level; i++)
        if(col[i] == col[level] || abs(col[level] - col[i]) == level - i)
            return false;
    return true;
}
void dfs(int x)
{
    if (x == N)
    {
        answer++;
        return;
    }

    for (int i = 0; i < N; i++)
    {
        col[x] = i;
        if(check(x)) dfs(x+1);
    }
}
int main()
{
    cin >> N;
    half = N % 2 == 0 ? N / 2 : (N / 2) + 1;
    graph.resize(N, vector<int>(N, 0));
    col.resize(N, 0);
    if (N == 1)
    {
        cout << N;
        return 0;
    }

    dfs(0);

    cout << answer;
    return 0;
}