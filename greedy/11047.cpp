#include <bits/stdc++.h>
using namespace std;

int main(){
    int answer=0;
    int N,K;
    cin>>N>>K;
    vector<int> v;
    for(int i=0; i<N; i++){
        int t=0;
        cin>>t;
        v.push_back(t);
    }
    for(int i=v.size()-1; i>=0; i--){
        while(true){
            if(K>=v[i]){
                K-=v[i];
                answer++;
            }
            else break;
        }
    }
    cout<<answer;
    return 0;
}
