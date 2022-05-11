// 2022-05-11 18:01:30
// 위상정렬 연습

// 2022-05-11 18:15:22 AC
// 얼떨떨 하다
// 좀 익숙해져야 할것 같다
// 어떤 그래프(연결성있는 객체)에서 순서를 '정해야' 한다면 
// 위상 정렬을 생각해봐야 할 것
#include <bits/stdc++.h>
using namespace std;

int V, E;
vector<vector<int>> graph;
vector<int> indegree;
vector<int> answer;

void topology_sort(){
    queue<int> q;
    for(int i=0; i<indegree.size(); i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        answer.push_back(cur);
        for(int i=0; i<graph[cur].size(); i++){
            int node = graph[cur][i];
            indegree[node]--;
            if(indegree[node]==0){
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

    cin>>V>>E;
    graph.resize(V);
    indegree.resize(V,0);
    for(int i=0; i<E; i++){
        int from,to;
        cin>>from>>to;
        from--; to--;
        graph[from].push_back(to);
        indegree[to]++;
    }
    topology_sort();
    for(auto e : answer){
        cout<<e+1<<" ";
    }
}