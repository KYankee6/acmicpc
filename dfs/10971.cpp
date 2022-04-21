// 2022-04-21 00:53:00 문제 분석 했음
// dfs식으로 가서 dfs(depth, visited)를 넘기고 answer = min(answer,total_cost); dfs의 return을 한 간선의 cost로 하자.
// 단 depth==N이 아닌 경우 순회를 못했던 경우이므로 answer로 받아선 안됨. 이때는 -1로 넘기자.

#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> W;

int dfs(int src, int depth, vector<bool> visited)
{
    if(visited[src]) return 0;
    if (depth == N)
    {
        // return W[src][dest];
    }
    visited[src] = true;
    int result = 0;
    for (int i = 0; i < W[src].size(); i++)
    {
        if (W[src][i] != 0)
        {
            dfs(i, depth + 1, visited);
            result += W[src][i];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int answer = pow(10, 9) + 1;
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
        int result = dfs(i, 0, visited);
        if (result != -1)
            answer = min(answer, result);
    }
    cout << answer;
}