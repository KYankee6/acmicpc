#include <bits/stdc++.h>
using namespace std;

int main()
{
    int answer=0;
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> v(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end(),greater<int>());
    for(int i=0; i<M/(K+1); i++){
        answer+=v[0]*K;
        answer+=v[1];
    }
    if(M%(K+1)!=0)answer +=v[0]*(M%(K+1));
    cout<<answer;
}