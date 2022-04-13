// #include <bits/stdc++.h>

// using namespace std;
// int N, M, R;
// vector<vector<int>> v;
// void func_one()
// {
//     for (int src = 0; src < N / 2; src++)
//     {
//         int tgt = (N - 1) - src;
//         vector<int> temp = v[src];
//         v[src] = v[tgt];
//         v[tgt] = temp;
//     }
// }

// void func_two()
// {
//     for (int src = 0; src < M / 2; src++)
//     {
//         int tgt = (M - 1) - src;
//         for (int j = 0; j < N; j++)
//         {
//             int temp = v[j][src];
//             v[j][src] = v[j][tgt];
//             v[j][tgt] = temp;
//         }
//     }
// }

// void func_three()
// {
//     vector<vector<int>> temp;
//     for (int i = 0; i < M; i++)
//     {
//         vector<int> arr;
//         for (int j = N - 1; j >= 0; j--)
//         {
//             arr.push_back(v[j][i]);
//         }
//         temp.push_back(arr);
//     }
//     v = temp;
//     int itemp = N;
//     N = M;
//     M = itemp;
// }

// void func_four()
// {
//     vector<vector<int>> temp;
//     for (int i = M - 1; i >= 0; i--)
//     {
//         vector<int> arr;
//         for (int j = 0; j < N; j++)
//         {
//             arr.push_back(v[j][i]);
//         }
//         temp.push_back(arr);
//     }
//     v = temp;
//     int itemp = N;
//     N = M;
//     M = itemp;
// }

// void func_five()
// {
//     vector<vector<int>> copy = v;
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < M; j++)
//         {
//             if (i < N / 2)
//             {
//                 if (j < M / 2)
//                     v[i][j] = copy[i + N / 2][j];
//                 else
//                     v[i][j] = copy[i][j - M / 2];
//             }
//             else
//             {
//                 if (j < M / 2)
//                     v[i][j] = copy[i][j + M / 2];
//                 else
//                     v[i][j] = copy[i - N / 2][j];
//             }
//         }
//     }
// }

// void func_six()
// {
//     vector<vector<int>> copy = v;
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < M; j++)
//         {
//             if (i < N / 2)
//             {
//                 if (j < M / 2)
//                     v[i][j] = copy[i][j + M / 2];
//                 else
//                     v[i][j] = copy[i + N / 2][j];
//             }
//             else
//             {
//                 if (j < M / 2)
//                     v[i][j] = copy[i - N / 2][j];
//                 else
//                     v[i][j] = copy[i][j - M / 2];
//             }
//         }
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     cin >> N >> M >> R;
//     v.resize(N, vector<int>(M, 0));
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < M; j++)
//         {
//             cin >> v[i][j];
//         }
//     }
//     for (int i = 0; i < R; i++)
//     {
//         int op;
//         cin >> op;
//         switch (op)
//         {
//         case 1:
//         {
//             func_one();
//             break;
//         }
//         case 2:
//         {
//             func_two();
//             break;
//         }
//         case 3:
//         {
//             func_three();
//             break;
//         }
//         case 4:
//         {
//             func_four();
//             break;
//         }
//         case 5:
//         {
//             func_five();
//             break;
//         }
//         case 6:
//         {
//             func_six();
//             break;
//         }
//         }
//     }
//     for (auto av : v)
//     {
//         for (auto e : av)
//         {
//             cout << e << " ";
//         }
//         cout << "\n";
//     }
//     return 0;
// }

#include <iostream>

using namespace std;

int arr[100][100];
int N, M, R;

void PrintArr(int localArr[][100], int n = N, int m = M)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << localArr[i][j] << " ";
        }
        cout << endl;
    }
}

void InitArr(int srcArr[][100], int dstArr[][100])
{
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            dstArr[i][j] = srcArr[i][j];
}

void Cal1()
{
    int tmpArr[100][100];
    for (int i = 0; i < N / 2; i++)
    {
        for (int j = 0; j < M; j++)
        {
            swap(arr[i][j], arr[N - i - 1][j]);
        }
    }
}

void Cal2()
{
    int tmpArr[100][100];
    for (int j = 0; j < M / 2; j++)
    {
        for (int i = 0; i < N; i++)
        {
            swap(arr[i][j], arr[i][M - j - 1]);
        }
    }
}

void Cal3()
{
    int tmpArr[100][100];
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            tmpArr[i][j] = arr[N - j - 1][i];
        }
    }
    swap(M, N);
    InitArr(tmpArr, arr);
}

void Cal4()
{
    int tmpArr[100][100];
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            tmpArr[i][j] = arr[j][M - i - 1];
        }
    }
    swap(M, N);
    InitArr(tmpArr, arr);
}

void Cal5()
{
    int tmpArr[100][100];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (i < N / 2 && j < M / 2)
                tmpArr[i][j + M / 2] = arr[i][j];
            else if (i < N / 2 && j >= M / 2)
                tmpArr[i + N / 2][j] = arr[i][j];
            else if (i >= N / 2 && j >= M / 2)
                tmpArr[i][j - N / 2 ] = arr[i][j];
            else if (i >= N / 2 && j < M / 2)
                tmpArr[i - M / 2 ][j] = arr[i][j];
        }
    }
    InitArr(tmpArr, arr);
}

void Cal6()
{
    int tmpArr[100][100];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (i < N / 2 && j < M / 2)
                tmpArr[i + M / 2 - 1][j] = arr[i][j];
            else if (i < N / 2 && j >= M / 2)
                tmpArr[i][j - M / 2] = arr[i][j];
            else if (i >= N / 2 && j >= M / 2)
                tmpArr[i - N / 2][j] = arr[i][j];
            else if (i >= N / 2 && j < M / 2)
                tmpArr[i][j + N / 2 + 1] = arr[i][j];
        }
    }
    InitArr(tmpArr, arr);
}

int main()
{
    cin >> N >> M >> R;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> arr[i][j];

    for (int i = 0; i < R; i++)
    {
        int rNum = 0;
        cin >> rNum;
        switch (rNum)
        {
        case 1:
            Cal1();
            break;
        case 2:
            Cal2();
            break;
        case 3:
            Cal3();
            break;
        case 4:
            Cal4();
            break;
        case 5:
            Cal5();
            break;
        case 6:
            Cal6();
            break;
        }
        PrintArr(arr, N, M);
    }
}
