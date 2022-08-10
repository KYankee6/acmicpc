#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n,m;
    int cnt=0;
    vector<string> v;
    map<string, int> board;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        board[s]=1;
    }
    for(int i=0; i<m; i++){
        string s;
        cin>>s;
        if(board.find(s)!=board.end()){
            cnt++;
            v.push_back(s);
        }
    }
    cout<<cnt<<"\n";
    sort(v.begin(),v.end());
    for(auto e : v){
        cout<<e<<"\n";
    }
    return 0;
}
