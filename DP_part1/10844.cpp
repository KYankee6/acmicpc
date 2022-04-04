#include <iostream>
#include <numeric>
using namespace std;

const int MOD = (int)1e9;

long long dp[101][10];

int main()
{
    int N;
    long long answer = 0LL;
    cin >> N;
    for (int i = 0; i <= 9; i++)
    {
        dp[1][i] = 1;
    }
    dp[2][0]=1;
    dp[2][1]=1;
    for(int i=2; i<=8; i++){
        dp[2][i]=2;
    }
    dp[2][9]=1;
    for (int i = 3; i <= 100; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (j % 10 == 0)
            {
                dp[i][j] = dp[i - 1][j + 1] % MOD;
            }
            else if (j % 10 == 9)
            {
                dp[i][j] = dp[i - 1][j - 1] % MOD;
            }
            else
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
            }
        }
    }
    for (int i = 0; i <= 9; i++)
    {
        answer += dp[N][i] % MOD;
    }
    cout << answer%MOD;
}