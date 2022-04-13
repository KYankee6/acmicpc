#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<int> v;
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }
    if (next_permutation(v.begin(), v.end()))
    {
        for (auto e : v) cout<<e<<" ";
    }
    else cout<<"-1";
    return 0;
}