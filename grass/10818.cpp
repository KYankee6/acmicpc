#include <bits/stdc++.h>

using namespace std;

int main(){
    int max = INT_MIN;
    int min = INT_MAX;

    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        int t;
        cin>>t;
        if(max<t){max=t;}
        if(min>t){min=t;}
    }
    cout<<min<<" "<<max;
    return 0;
}