// 2022-09-18 20:19:10
// https://www.acmicpc.net/problem/5635 생일

#include <bits/stdc++.h>
using namespace std;

bool cmp_asc(pair<double, string> p1, pair<double, string> p2)
{
    return p1.first < p2.first;
}
bool cmp_desc(pair<double, string> p1, pair<double, string> p2)
{
    return p1.first > p2.first;
}

int main()
{
    int n;
    vector<pair<double, string>> v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string name;
        int d, m, y;
        cin >> name >> d >> m >> y;
        v.push_back({d + 30.14 * m + y * 365, name});
    }
    sort(v.begin(), v.end(), cmp_desc);
    cout << v[0].second << endl;
    sort(v.begin(), v.end(), cmp_asc);
    cout << v[0].second << endl;
}