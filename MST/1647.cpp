// 2022-05-12 00:41:54
// 도시분할 계획
// MST 문제를 사용하여 마을을 분리하고, 이중 MST를 찾는 문제로 보인다.
// O(ElogE) <= 1,000,000 * 15 이므로 충분히 분할 할 수 있어 보인다


// 문제 조건을 제대로 읽지 않아서 한가지 처리한 점
// 마을을 '두개로' 나눈다
// 즉 MST를 만들고 max_cost인 다리를 끊어줘야 했다.
// 다행히도 구현에는 큰 문제가 생기지 않았지만
// 상태가 매롱이라..
// 2022-05-12 00:53:10 AC

#include <bits/stdc++.h>
using namespace std;

int answer;
int N, M;
vector<tuple<int, int, int>> graph;
vector<int> parent;

bool cmp(tuple<int, int, int> &t1, tuple<int, int, int> &t2)
{
    return get<2>(t1) < get<2>(t2);
}

int get_root(int x)
{
    if (parent[x] == x)
        return x;
    else
        return parent[x] = get_root(parent[x]);
}

void union_parent(int a, int b)
{
    int pa = get_root(a);
    int pb = get_root(b);

    if (pa < pb)
        parent[pb] = pa;
    else
        parent[pa] = pb;
}

bool is_unioned(int a, int b)
{
    return get_root(a) == get_root(b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int max_cost = INT_MIN;
    cin >> N >> M;
    parent.resize(N);
    iota(parent.begin(), parent.end(), 0);
    for (int i = 0; i < M; i++)
    {
        int src, dest, cost;
        cin>>src>>dest>>cost;
        graph.push_back({src-1,dest-1,cost});
    }
    sort(graph.begin(),graph.end(),cmp);

    for(int i=0; i<graph.size(); i++){
        int a = get<0>(graph[i]);
        int b = get<1>(graph[i]);
        int cost = get<2>(graph[i]);
        if(!is_unioned(a,b)){
            union_parent(a,b);
            answer+=cost;
            if(max_cost<cost)max_cost=cost;
        }
    }
    cout<<answer-max_cost;
    return 0;
}