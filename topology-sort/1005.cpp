// 2022-05-11 18:21:21
// 위상정렬 연습

// 복붙 했기때문에 시간은 더 적게 걸릴 것 같다.
// 생각한 구현 방법은 다음과 같다.
// 먼저 위상정렬을 위한 graph와 weight를 따로 지정한다
// 그 후 indegree가 0일때 바로 집어넣는게 아니라
// 그 그래프가 갖는 모든 인접 리스트가 0일때까지 (while) 돌린 후 집어넣어 보는게 어떨까
// 안될것같다 될것같은데? 오히려 weight와 조건이 가능하게 만드는것 같은데?

// 2022-05-11 18:25:09 구현해봄 알게찌..
// 선수 공사를 마쳐야 하는 리스트를 구현해보자
// 2D vector로 idx로 쓰자
// 선수 공사가 끝났는지를 확인하는 리스트를 구현하자
// 1D vector bool idx로 쓰자
#include <bits/stdc++.h>
using namespace std;

int V, E, W;

// 살짝 BFS 식으로 풀어본 문제
// 문제점
// pre-requisite의 indegree를 고려하지 못함.
// 오우 이거 안되겠따

// int myFunc(vector<int> &indegree, vector<int> &weights, vector<set<int>> &pre_req)
// {
//     int result = 0;
//     vector<bool> visited(V, false);
//     vector<int> left_sum;
//     set<int> cur_pre_req = pre_req[W];
//     int cur_indeg = 0;
//     while (true)
//     {
//         bool no_indeg = true;
//         int cur_max = INT_MIN;
//         set<int> next_pre_req;
//         for (auto iter : cur_pre_req)
//         {
//             if (visited[iter])
//                 continue;

//             visited[iter] = true;

//             if (cur_max < weights[iter])
//                 cur_max = weights[iter];
//             if (indegree[iter] != 0)
//             {
//                 no_indeg = false;
//             }
//         }
//         if (cur_max != INT_MIN)
//             result += cur_max;
//         else
//             break;
//         if (no_indeg)
//             break;

//         for (auto iter : cur_pre_req)
//         {
//             next_pre_req.insert(pre_req[iter].begin(), pre_req[iter].end());
//             next_pre_req.insert(iter);
//         }
//         cur_indeg++;
//         cur_pre_req = next_pre_req;
//     }
//     return result + weights[W];
// }

// 톺솔의 한가지 문제점
// 동시에 건물 짓는 지를 모른다
// 그렇다면 일단 W까지의 순서만 정해놓고,
// 앞에 녀석들이 동시에 지어지는지 안지어지는지를 어떻게 구별할까?

// 2022-05-13 18:22:15 DP로 해결하는것 같다..

int topology_sort(vector<int> &indegree, vector<int> &weights, vector<vector<int>> &graph)
{
    vector<int> result = weights;
    queue<int> q;
    for (int i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < graph[cur].size(); i++)
            {
                int node = graph[cur][i];
                indegree[node]--;
                result[node] = max(result[node],result[cur]+weights[node]);
                if (indegree[node] == 0)
                {
                    q.push(node);
                }
            }
        }
    return result[W];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        cin >> V >> E;
        vector<int> weights(V, 0);
        vector<int> indegree(V, 0);
        vector<vector<int>> graph(V);
        vector<int> pre_req;
        for (int i = 0; i < V; i++)
        {
            cin >> weights[i];
        }
        for (int i = 0; i < E; i++)
        {
            int from, to;
            cin >> from >> to;
            from--;
            to--;
            indegree[to]++;
            graph[from].push_back(to);
        }
        cin >> W;
        W--;

        cout << topology_sort(indegree, weights, graph) << "\n";
    }
}