#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, M;
    cin >> N >> M;
    long long sum[1024*1024+1];
    cin >> sum[0];
    for (int i = 1; i < N * N; i++)
    {
        int t;
        cin >> t;
        sum[i] = t + sum[i - 1];
    }
    while (M--)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        x2--;
        y1--;
        y2--;
        int start = x1 * N + y1;
        int end = x2 * N + y2;

        if (start == end)
        {
            if (start != 0)
                cout << sum[start] - sum[start - 1] << "\n";
            else
            {
                cout << sum[0] << "\n";
            }
        }
        else
        {

            long long answer = sum[(end / N) * N + N - 1];

            if (start / N != 0)
                answer -= sum[max((start / N) * N - 1, N - 1)];
            for (int i = x1; i <= x2; i++)
            {
                if (y1 != 0)
                {
                    if (i * N - 1 == -1)
                        answer -= sum[i * N + y1 - 1];

                    else
                        answer -= (sum[i * N + y1 - 1] - sum[i * N - 1]);
                }
                if (y2 != N - 1)
                    answer -= (sum[i * N + (N - 1)] - sum[i * N + y2]);
            }
            cout << answer << "\n";
        }
    }
    return 0;
}