#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<char> src;
vector<char> dest;

int getPollToIdx(char poll)
{
    if (poll == 'A')
        return 0;
    if (poll == 'B')
        return 1;
    if (poll == 'C')
        return 2;
}

char getEmptyPoll(char from, char to)
{
    if (from == 'A' && to == 'B')
    {
        return 'C';
    }

    if (from == 'A' && to == 'C')
    {
        return 'B';
    }

    // case 2
    if (from == 'B' && to == 'A')
    {
        return 'C';
    }
    if (from == 'B' && to == 'C')
    {
        return 'A';
    }

    // case 3
    if (from == 'C' && to == 'A')
    {
        return 'B';
    }
    if (from == 'C' && to == 'B')
    {
        return 'A';
    }
}
void hanoi(int n, int from, int by, int to)
{
    if (n == 1)
    {
        src[from] = dest[to];
        return;
    }
    hanoi(n - 1, from, to, by);
    hanoi(n - 1, by, from, to);
}

int main()
{
    cin >> N >> M;
    vector<int> dp(N + 1, 0);
    src.resize(N, 'A');
    dest.resize(N, 'A');
    dp[1] = 1;
    dp[2] = 3;
    for (int i = 3; i <= N; i++)
    {
        // N-1까지의 원판 움직이기 to temp(dp[i-1]) + N번째 원판 움직이기(1) + N-1원판 다시 올리기 (dp[i-1])
        dp[i] = (1 << i) - 1;
    }
    for (int i = 0; i < N; i++)
    {
        cin >> dest[i];
    }
    int walk = 1;
    int bound = N - 1;
    while (true)
    {
        while (true)
        {
            if (M - dp[walk] <= 0)
            {
                M -= dp[walk - 1];
                for (int i = 0; i < walk - 1; i++)
                {
                    src[i] = getEmptyPoll(src[bound], dest[bound]);
                }
                break;
            }
            else if (walk == bound + 1)
            {
                M -= dp[walk];
                for (int i = 0; i < walk - 1; i++)
                {
                    src[i] = getEmptyPoll(src[bound], dest[bound]);
                }
                break;
            }
            walk++;
        }
        if (M - dp[walk - 1] > 0)
        {
            walk = 1;
            bound--;
        }
        else
        {
            break;
        }
    }
    int idx = walk;
    if (idx == bound + 1)
        idx = bound - 1;
    hanoi(M, 
    for (auto e : src)
    {
        cout << e;
    }
    return 0;
}
}