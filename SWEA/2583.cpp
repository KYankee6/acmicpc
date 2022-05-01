#include <bits/stdc++.h>
#define in_range(x,y) x>=0 && y>=0 && x<N && y<M
using namespace std;

int N,M,K;
int answer;
priority_queue<int> pq;
vector<vector<int>> graph;
vector<vector<bool>> visited;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void bfs(pair<int,int> start){
    int result=0;
    answer++;
    queue<pair<int,int>> q;
    q.push(start);
    visited[start.first][start.second]=true;
    while(!q.empty()){
        auto cur =q.front();
        q.pop();
        result++;
        graph[cur.first][cur.second]=1;
        for(int i=0; i<4; i++){
            int px= cur.first + dx[i];
            int py= cur.second + dy[i];
            if(in_range(px,py) && !visited[px][py]&&graph[px][py]==0){
                visited[px][py]=true;
                q.push({px,py});
            }
        }
    }
    pq.push(-result);
}

void fill_box(pair<int,int> p1,pair<int,int> p2){
    for(int i=p1.first; i<p2.first; i++){
        for(int j=p1.second; j<p2.second; j++){
            graph[i][j]=1;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>N>>M>>K;
    graph.resize(N,vector<int>(M,0));
    visited.resize(N,vector<bool>(M,false));
    for(int i=0; i<K; i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        fill_box({y1,x1},{y2,x2});
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(graph[i][j]==0) bfs({i,j});
        }
    }
    cout<<answer<<"\n";
    while(!pq.empty()){
        cout<<-pq.top()<<" ";
        pq.pop();   
    }
}
