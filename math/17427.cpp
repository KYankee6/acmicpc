#include <bits/stdc++.h>
#define ll long long 
using namespace std;


int main(){
    ll result=0L;
    int N;
    cin>>N;

    vector<ll> v(N+1,0);
    for(int i=1; i<=N; i++){
        result += i*(N/i);
    }
    cout<<result;
}