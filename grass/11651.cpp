#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool cmp(const pair<int,int>& p1, const pair<int,int>& p2){
    return p1.second==p2.second ? p1.first<p2.first : p1.second<p2.second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin>>N;
    vector<pair<int,int>> v; 
    for(int i=0; i<N; i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0; i<N; i++){
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }
    return 0;
}