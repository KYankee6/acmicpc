#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    set<int> s;
    int N;
    cin >>N;
    for(int i=0; i<N; i++){
        int temp;
        cin>> temp;
        s.insert(temp);
    }
    for(auto iter : s){
        cout<<(iter)<<" ";
    }
    return 0;

}