// 2022-04-14 16:11:36 구현으로 갖다 박으려했는데 시간초과남
//                      N - (N보다 같거나 작은 제곱수)를 빼는 방식
// 2022-04-14 16:33:13 그런 방식으로는 문제를 해결할 수 없어
//                      그런 방식이었는데 조금 다른 방식이었다, dp를 2번 업데이트 해줘야함

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> dp(100001, 0);
    for(int i=1; i<=N; i++) dp[i]=i;
    for(int i=1; i<=N; i++){
        for(int j=1; j*j<=i; j++){
            dp[i] = min(dp[i],dp[i-j*j]+1);
        }
    }
    cout << dp[N];
}