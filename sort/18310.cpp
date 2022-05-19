// https://www.acmicpc.net/problem/18310
// 안테나
// 2022-05-19 12:59:13 

// 가운데에 있는게 가장 작을 것 같다.

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin>>N;
    vector<int>v(N,0);
    for(int i=0; i<N; i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    N %2 ==0 ? N=(N-1)/2 : N=N/2;
    cout<<v[N];
    return 0;
}
