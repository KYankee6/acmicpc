#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<char> src;
vector<char> dest;
void hanoi(int n, int from, int by, int to)
{
    if (M == 0)
    {
        return;
    }
    M--;
    if (n == 1)
    {
        src[n] = to;
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
    int walk = M - 1;
    char empty_poll = 'B';
    while (true)
    {
        if (src[walk] != dest[walk])
        {
            if (M - dp[walk] <= 0)
            {
                break;
            }
            // case 1
            if (src[walk] == 'A' && dest[walk] == 'B')
            {
                for (int i = 0; i < walk - 1; i++)
                {
                    src[i] = 'C';
                }
                src[walk] = 'B';
            }

            if (empty_poll == 'A' && dest[walk] == 'C')
            {
                for (int i = 0; i < walk - 1; i++)
                {
                    src[i] = 'B';
                }
                src[walk] = 'C';
            }

            // case 2
            if (src[walk] == 'B' && dest[walk] == 'A')
            {
                for (int i = 0; i < walk - 1; i++)
                {
                    src[i] = 'C';
                }
                src[walk] = 'A';
            }
            if (src[walk] == 'B' && dest[walk] == 'C')
            {
                for (int i = 0; i < walk - 1; i++)
                {
                    src[i] = 'A';
                }
                src[walk] = 'C';
            }

            // case 3
            if (src[walk] == 'C' && dest[walk] == 'A')
            {
                for (int i = 0; i < walk - 1; i++)
                {
                    src[i] = 'B';
                }
                src[walk] = 'A';
            }
            if (src[walk] == 'C' && dest[walk] == 'B')
            {
                for (int i = 0; i < walk - 1; i++)
                {
                    src[i] = 'A';
                }
                src[walk] = 'B';
            }
            M -= dp[walk - 1];
        }
        walk--;
    }

    if (src[walk] == 'A' && dest[walk] == 'B')
    {
        hanoi(walk, 'A', 'C', 'B');
    }

    if (empty_poll == 'A' && dest[walk] == 'C')
    {
        hanoi(walk, 'A', 'B', 'C');
    }

    // case 2
    if (src[walk] == 'B' && dest[walk] == 'A')
    {
        hanoi(walk, 'B', 'C', 'A');
    }
    if (src[walk] == 'B' && dest[walk] == 'C')
    {
        hanoi(walk, 'B', 'A', 'C');
    }

    // case 3
    if (src[walk] == 'C' && dest[walk] == 'A')
    {
        hanoi(walk, 'C', 'B', 'A');
    }
    if (src[walk] == 'C' && dest[walk] == 'B')
    {
        hanoi(walk, 'C', 'A', 'B');
    }
    for (auto e : src)
    {
        cout << e;
    }
    return 0;
}