// https://www.acmicpc.net/problem/1037
// 2022-09-11 16:37:00

#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int N;
    int arr[100]={0};

    cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    sort(arr,arr+N,less<int>());
    cout<<arr[0]*arr[N-1];
    return 0;
    
}