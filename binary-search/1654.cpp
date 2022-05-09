#include <bits/stdc++.h>
using namespace std;

int N, K;
int answer;

int get_number_of_cable(vector<int> &v, int crit)
{
    int result = 0;
    for (int i = 0; i < v.size(); i++)
    {
        result += v[i] / crit;
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> K;
    vector<int> v(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int start = 0;
    int end = *max_element(v.begin(),v.end());
    int mid = 0;
    if (get_number_of_cable(v, end) >= K){
        cout<<v[N - 1];
        return 0;
    }
    bool check_mid_one = false;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if(mid==1){
            check_mid_one=true;
        }
        if(mid==0&&!check_mid_one){
            mid=1;
        }
        int result = get_number_of_cable(v, mid);
        if (result >= K)
        {
            answer = max(answer, mid);
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    cout << answer;
    return 0;
}