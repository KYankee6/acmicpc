#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int answer = 0;
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    if(s1.size()<s2.size()){
        cout<<0;
        return 0;
    }
    for (int i = 0; i < s1.size() - s2.size()+1; i++)
    {
        bool match = true;
        for (int j = 0; j < s2.size(); j++)
        {
            if (s1[i + j] != s2[j])
                match = false;
        }
        if (match)
        {
            answer++;
            i += s2.size() - 1;
        }
    }
    cout << answer;
    return 0;
}