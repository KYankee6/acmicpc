// 2022-04-21 00:53:00 문제 분석 했음
// dfs식으로 가서 dfs(depth, visited)를 넘기고 answer = min(answer,total_cost); dfs의 return을 한 간선의 cost로 하자.
// 단 depth==N이 아닌 경우 순회를 못했던 경우이므로 answer로 받아선 안됨. 이때는 -1로 넘기자.

#include <bits/stdc++.h>

using namespace std;

int N;
int answer = INT_MAX;
vector<vector<int>> W;

void dfs(int src, int start, int depth, int cost, vector<bool> &visited)
{
    visited[src] = true;
    if (depth == N - 1 && W[src][start] != 0)
    {
        answer = min(answer, W[src][start] + cost);
        return;
    }
    for (int i = 0; i < W[src].size(); i++)
    {
        if (!visited[i] && W[src][i] != 0)
        {
            cost += W[src][i];
            dfs(i, start, depth + 1, cost, visited);
            cost -= W[src][i];
            visited[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    W.resize(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> W[i][j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        vector<bool> visited(N, false);
        dfs(i, i, 0, 0, visited);
    }
    cout << answer;
}