

// 2022-04-13 02:00:27 점화식 생각중
// 2022-04-13 02:44:18 점화식 멱 멱 급수? 아니 그 뭐시깽이
//                      dp[i][~] = 전에꺼 + dp[i-1][~]임 ㄹㅈㄷ
// 2022-04-13 02:47:55 해냈다 해냈어~


#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;



int main(){
    int N,K;
    cin>>N>>K;
    vector<vector<ll>> dp(201,vector<ll>(201,0));
    for(int i=1; i<201; i++)dp[0][i]=1;
    for(int i=1; i<201; i++)dp[1][i]=i;
    dp[2][1]=1;
    for(int i=2; i<201; i++)dp[2][i]=dp[2][i-1]+i;
    for(int i=2; i<=200; i++){
        for(int j=1; j<=200; j++){
            dp[i][j] = (dp[i][j-1] + dp[i-1][j])%1000000000;
        }
    }
    cout<<dp[N][K]%1000000000;
    return 0;
}