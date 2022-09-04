// 2022-09-04 14:21:40
// https://www.acmicpc.net/problem/1406 에디터

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int M;
    string s;
    cin >> s;
    cin >> M;
    list<char> li;
    list<char>::iterator it;
    for (int i = 0; i < s.size(); i++)
    {
        li.push_back(s[i]);
    }
    it = li.end();
    while (M--)
    {
        char op;
        cin >> op;
        if (op == 'L')
        {
            if (it != li.begin())
                it--;
        }
        else if (op == 'D')
        {
            if (it != li.end())
                it++;
        }
        else if (op == 'B')
        {
            if (it != li.begin())
            {
                it--;
                it = li.erase(it);
            }
        }
        else if (op == 'P')
        {
            char in;
            cin >> in;
            li.insert(it, in);
        }
    }
    for (char c : li)
    {
        cout << c;
    }
}
