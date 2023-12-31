#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, pair<int,int>>p1, pair<int, pair<int,int>>p2){
    return p1.second.first > p2.second.first && p1.second.second > p2.second.second;
}

int main(){
    vector<pair<int, pair<int,int>>> v; 
    int idx=1;
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({i, {x,y}});
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            
        }
    }
}