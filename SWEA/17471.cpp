// 2022-04-22 02:16:16 문제 이해 끝
// priority_queue tuple <int,vector,vector> 보다는 비트마스킹을 쓰는게 매우 뭐랄까,, 정상적이게 보이지만 처음 생각이 vector<int>였다
// 되는지는... 2^10 x 4byte 니까는,, 되지않을까요 ㅠ?
// 해보고 안되면 비트마스크로 바꿔서 돌릴수 이따.
// 2022-04-22 02:19:10 구현 시작.

// 시간떄문에 dfs를 써야할지도 모르겠다는 생각이.

// 2022-04-22 03:10:51 컽!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> graph;
vector<int> weight;
priority_queue<tuple<int, vector<int>, vector<int>>> pq;

bool bfs(vector<int> &sub_graph)
{
    vector<int> shadow_graph;
    vector<bool> visited(N, false);
    queue<int> q;
    q.push(sub_graph[0]);
    visited[sub_graph[0]]=true;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < N; i++)
        {
            if (!visited[i] && graph[cur][i] == 1 && find(sub_graph.begin(), sub_graph.end(), i) != sub_graph.end())
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    for (int i = 0; i < sub_graph.size(); i++)
    {
        if (visited[sub_graph[i]] != true)
            return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    graph.resize(N, vector<int>(N, 0));
    weight.resize(N, 0);

    vector<bool> rotator(N, false);

    // 사람 숫자 정보 리스트
    for (int i = 0; i < N; i++)
    {
        cin >> weight[i];
    }

    // bfs를 위한 인접 리스트
    for (int i = 0; i < N; i++)
    {
        int M;
        cin >> M;
        for (int j = 0; j < M; j++)
        {
            int E;
            cin >> E;
            E--;
            graph[i][E] = 1;
            graph[E][i] = 1;
        }
    }

    // NCr
    for (int r = 0; r < N - 1; r++)
    {
        rotator[r] = true;
        do
        {
            vector<int> g1;
            int g1_total = 0;
            vector<int> g2;
            int g2_total = 0;
            for (int i = 0; i < N; i++)
            {
                if (rotator[i])
                {
                    g1.push_back(i);
                    g1_total += weight[i];
                }
                else
                {
                    g2.push_back(i);
                    g2_total += weight[i];
                }
            }
            pq.push({-abs(g1_total - g2_total), g1, g2});
        } while (prev_permutation(rotator.begin(), rotator.end()));
    }
    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        if (bfs(get<1>(top)) && bfs(get<2>(top)))
        {
            cout << -get<0>(top);
            return 0;
        }
    }
    cout << -1;
    return 0;
}
