// 2022-04-27 19:59:27 MST 우마이
// 구현시작
// 2022-04-27 20:08:34 AC
// 프림으로 구현해보자.
// #include <bits/stdc++.h>

// using namespace std;

// vector<tuple<int, int, int>> costs;
// vector<int> parent;

// int get_root(int x)
// {
//     if (parent[x] == x)
//         return x;
//     return get_root(parent[x]);
// }

// void union_parent(int a, int b)
// {
//     int par_a = get_root(a);
//     int par_b = get_root(b);
//     if (par_a < par_b)
//         parent[par_b] = par_a;
//     else
//         parent[par_a] = par_b;
// }

// bool find(int a, int b)
// {
//     return get_root(a) == get_root(b);
// }

// bool cmp(tuple<int, int, int> t1, tuple<int, int, int> t2)
// {
//     return get<2>(t1) < get<2>(t2);
// }
// int N, M;
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);

//     int answer = 0;
//     cin >> N >> M;
//     parent.resize(N, 0);
//     iota(parent.begin(), parent.end(), 0);
//     for (int i = 0; i < M; i++)
//     {
//         int src, dest, cost;
//         cin >> src >> dest >> cost;
//         if (src == dest)
//             continue;

//         costs.push_back({src - 1, dest - 1, cost});
//     }
//     sort(costs.begin(),costs.end(),cmp);
//     for (int i = 0; i < costs.size(); i++)
//     {
//         auto cur = costs[i];
//         int src = get<0>(cur);
//         int dest = get<1>(cur);
//         int cost = get<2>(cur);
//         if (!find(src, dest))
//         {
//             union_parent(src, dest);
//             answer += cost;
//         }
//     }
//     cout << answer;
// }

#include <bits/stdc++.h>

using namespace std;

int N, M;
int answer = 0;

priority_queue<pair<int, int>> costs; // 0-> cost, 1-> src, 2-> dest
vector<vector<int>> graph;            // 0-> cost, 1-> src, 2-> dest
vector<bool> visited;

void prim()
{
    costs.push({0, 0});

    while (!costs.empty())
    {
        auto cur = costs.top();
        costs.pop();
        int cost = -get<0>(cur);
        int cur_node = get<1>(cur);
        if (visited[cur_node])
            continue;
        visited[cur_node] = true;
        answer += cost;

        for (int i = 0; i < graph[cur_node].size(); i++)
        {
            auto next_cost = graph[cur_node][i];
            if (next_cost != 0 && !visited[i])
            {
                costs.push({-next_cost, i});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cnt = 0;
    cin >> N >> M;
    graph.resize(N, vector<int>(N, 0));
    visited.resize(N, false);
    for (int i = 0; i < M; i++)
    {
        int src, dest, cost;
        cin >> src >> dest >> cost;
        if (src == dest)
            continue;
        graph[src - 1][dest - 1] = cost;
        graph[dest - 1][src - 1] = cost;
    }
    prim();
    cout << answer;
}