#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> arr;
int T;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    arr.resize(15, vector<int>(15, 0));
    iota(arr[0].begin(), arr[0].end(), 0);
    for (int a = 1; a < 15; a++)
    {
        for (int b = 1; b < 15; b++)
        {
            for (int k = 1; k <= b; k++)
            {
                arr[a][b] += arr[a - 1][k];
            }
        }
    }
    while (T--)
    {
        int a, b;
        cin >> a >> b;
        cout << arr[a][b] << "\n";
    }
    return 0;
}