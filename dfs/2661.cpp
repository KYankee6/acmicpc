// https://www.acmicpc.net/problem/2661
// 2022-09-11 17:01:03 
// 2022-09-11 17:44:31

#include <bits/stdc++.h>
using namespace std;

int N;
vector<char> arr;
string answer = "";

bool checker(string &arr)
{
    int cnt = 1;
    while (true)
    {
        if (cnt > arr.size() / 2)
            return true;
        string s1 = "";
        string s2 = "";
        for (int i = 0; i < cnt; i++)
        {
            s1 += arr[(arr.size() - cnt) + i];
        }
        for (int i = 0; i < cnt; i++)
        {
            s2 += arr[(arr.size() - cnt * 2) + i];
        }
        if (s1.compare(s2) == 0)
        {
            return false;
        }
        cnt++;
    }
}

void dfs(string str)
{
    if (answer.compare("") != 0)
        return;
    if (!checker(str))
        return;
    else if (str.size() == N)
    {
        answer = str;
        return;
    }

    dfs(str + "1");
    dfs(str + "2");
    dfs(str + "3");
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    dfs(answer);
    cout << answer;
    return 0;
}