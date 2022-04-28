// 2022-04-28 22:13:15 이거 유니온파인드로는 못풀라나? 궁금해서 풀어보는 문제.
// 안되면 dfs로 바꿔야지
// 빡대가리;색기ㅏ

#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> answers;
int max_e = -1;
void dfs(int src, int idx, int cnt)
{
    if(visited[idx])return;
    answers[src]++;
    max_e=max(answers[src],max_e);
    visited[idx] = true;
    for (int i = 0; i < graph[idx].size(); i++)
    {
        int next = graph[idx][i];
        dfs(src, next, cnt + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    graph.resize(N);
    visited.resize(N, 0);
    answers.resize(N, 0);
    for (int i = 0; i < M; i++)
    {
        int px, py;
        cin >> py >> px;
        px--;
        py--;

        graph[px].push_back(py);
    }
    for (int i = 0; i < N; i++)
    {
        fill(visited.begin(),visited.end(),false);
        dfs(i, i, 0);
    }
    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == max_e)
        {
            cout << i + 1 << ' ';
        }
    }
}
