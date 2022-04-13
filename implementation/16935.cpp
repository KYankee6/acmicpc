#include <bits/stdc++.h>

using namespace std;
int N, M, R;
vector<vector<int>> v;
void func_one()
{
    for (int src = 0; src < N / 2; src++)
    {
        int tgt = (N - 1) - src;
        vector<int> temp = v[src];
        v[src] = v[tgt];
        v[tgt] = temp;
    }
}

void func_two()
{
    for (int src = 0; src < M / 2; src++)
    {
        int tgt = (M - 1) - src;
        for (int j = 0; j < N; j++)
        {
            int temp = v[j][src];
            v[j][src] = v[j][tgt];
            v[j][tgt] = temp;
        }
    }
}

void func_three()
{
    vector<vector<int>> temp;
    for (int i = 0; i < M; i++)
    {
        vector<int> arr;
        for (int j = N - 1; j >= 0; j--)
        {
            arr.push_back(v[j][i]);
        }
        temp.push_back(arr);
    }
    v = temp;
    int itemp = N;
    N = M;
    M = itemp;
}

void func_four()
{
    vector<vector<int>> temp;
    for (int i = M - 1; i >= 0; i--)
    {
        vector<int> arr;
        for (int j = 0; j < N; j++)
        {
            arr.push_back(v[j][i]);
        }
        temp.push_back(arr);
    }
    v = temp;
    int itemp = N;
    N = M;
    M = itemp;
}

void func_five()
{
    vector<vector<int>> copy = v;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (i < N / 2)
            {
                if (j < M / 2)
                    v[i][j] = copy[i + N / 2][j];
                else
                    v[i][j] = copy[i][j - M / 2];
            }
            else
            {
                if (j < M / 2)
                    v[i][j] = copy[i][j + M / 2];
                else
                    v[i][j] = copy[i - N / 2][j];
            }
        }
    }
}

void func_six()
{
    vector<vector<int>> copy = v;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (i < N / 2)
            {
                if (j < M / 2)
                    v[i][j] = copy[i][j + M / 2];
                else
                    v[i][j] = copy[i + N / 2][j];
            }
            else
            {
                if (j < M / 2)
                    v[i][j] = copy[i - N / 2][j];
                else
                    v[i][j] = copy[i][j - M / 2];
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M >> R;
    v.resize(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < R; i++)
    {
        int op;
        cin >> op;
        switch (op)
        {
        case 1:
        {
            func_one();
            break;
        }
        case 2:
        {
            func_two();
            break;
        }
        case 3:
        {
            func_three();
            break;
        }
        case 4:
        {
            func_four();
            break;
        }
        case 5:
        {
            func_five();
            break;
        }
        case 6:
        {
            func_six();
            break;
        }
        }
    }
    for (auto av : v)
    {
        for (auto e : av)
        {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

