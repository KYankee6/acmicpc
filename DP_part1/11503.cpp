#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int N;
    int dp[1001];
    int answer=0;
    cin >> N;
    fill(dp,dp+1001,0);
    vector<int> v(N, -1);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    for(int i=0; i<v.size()-1; i++){
        for(int j=i+1; j<v.size(); j++){
            if(v[i]<v[j]){
                dp[v[j]] = max(dp[v[j]], dp[v[i]]+1);
            }
        }
    }
    cout<<*max_element(dp,dp+1001)+1;
}