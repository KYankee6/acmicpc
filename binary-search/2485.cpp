// https://www.acmicpc.net/problem/2485
// 2022-09-11 18:06:08

#include <bits/stdc++.h>
using namespace std;

int N;
int min_diff = INT_MAX;
int answer = -1;

int linear_search(vector<int> &arr, int gap)
{
    if (gap == 0)
        return -1;
    int result = 0;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] + gap > arr[i + 1])
            return -1;
        if ((arr[i + 1] - arr[i]) % gap != 0)
            return -1;
        result += ((arr[i + 1] - arr[i]) / gap) - 1;
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    vector<int> arr(N);
    cin >> arr[0];
    for (int i = 1; i < N; i++)
    {
        cin >> arr[i];
        if (min_diff > arr[i] - arr[i - 1])
            min_diff = arr[i] - arr[i - 1];
    }

    // int start = arr[0], end = arr[N - 1];
    // while(start<=end){

    // }
    sort(arr.begin(), arr.end());

    int start = 0, end = 1000000000;
    int mid = 0;
    while (start <= end)
    {
        mid = (start + end) / 2;
        int ls_result = linear_search(arr, mid);
        if (ls_result == -1)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
            answer = ls_result;
        }
    }
    if (linear_search(arr, min_diff) != -1)
    {
        cout << linear_search(arr, min_diff);
    }
    else if (answer == -1)
    {
        cout << linear_search(arr, 1);
    }
    else
        cout << answer;
    return 0;
}