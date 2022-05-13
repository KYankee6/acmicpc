// 이코테 난이도 1 문제가 백준에서는 골드 3?


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> v(N);
    for(int i=0; i<N; i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int target=1;
    for(int i=0; i<N; i++){
        if(target<v[i]) break;
        target+= v[i];
    }
    cout<<target;
}
