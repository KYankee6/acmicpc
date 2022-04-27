#include <bits/stdc++.h>

using namespace std;

int get_root(vector<int>& parent, int x){
    if(parent[x]==x)return x;
    return parent[x]=get_root(parent,parent[x]);
}

void union_parent(vector<int>&parent, int x, int y){
    int parent_x = get_root(parent, x);
    int parent_y = get_root(parent, y);
    if(parent_x<parent_y) parent[parent_y]=parent_x;
    else parent[parent_x]=parent_y;
}

bool find(vector<int>& parent, int x, int y){
    return get_root(parent, x) == get_root(parent, y); 
}

bool cmp(vector<int> v1, vector<int> v2){
    return v1[2]<v2[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<int> parent(n);
    iota(parent.begin(),parent.end(),0);
    sort(costs.begin(),costs.end(), cmp);
    
    for(int i=0; i<costs.size(); i++){
        if(!find(parent,costs[i][0],costs[i][1])){
            union_parent(parent,costs[i][0],costs[i][1]);
            answer+=costs[i][2];
        }
    }
    return answer;
}
