// 2022-05-11 18:21:21
// 위상정렬 연습

// 복붙 했기때문에 시간은 더 적게 걸릴 것 같다.
// 생각한 구현 방법은 다음과 같다.
// 먼저 위상정렬을 위한 graph와 weight를 따로 지정한다
// 그 후 indegree가 0일때 바로 집어넣는게 아니라
// 그 그래프가 갖는 모든 인접 리스트가 0일때까지 (while) 돌린 후 집어넣어 보는게 어떨까
// 안될것같다 될것같은데? 오히려 weight와 조건이 가능하게 만드는것 같은데?

// 2022-05-11 18:25:09 구현해봄 알게찌..
#include <bits/stdc++.h>
using namespace std;

int V, E,W;

int topology_sort(vector<vector<int>> &graph, vector<int> &indegree)
{
    int result = 0;
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
        if(cur==W){
            
        }
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int node = graph[cur][i];
            indegree[node]--;
            if (indegree[node] == 0)
            {
                q.push(node);
            }
        }
    }
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
        vector<vector<int>> graph(V);
        vector<int> weights(V, 0);

        vector<int> indegree(V, 0);
        vector<int> answer;
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
            graph[from].push_back(to);
            indegree[to]++;
        }
        cin>>W;
        W--;
        topology_sort(graph, indegree);
        for (auto e : answer)
        {
            cout << e + 1 << " ";
        }
    }
}