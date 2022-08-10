#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N,M;
    vector<long long> arr;
    long long sum=0L;
    cin>>N>>M;
    arr.resize(N+1,0L);
    for(int i=0; i<N; i++){
        int val;
        cin>>val;
        sum+=val;
        arr[i+1]=sum;
    }   

    for(int i=0; i<M; i++){
        int a,b;
        cin>>a>>b;
        cout<<arr[b]-arr[a-1]<<"\n";
    }
    return 0;
}