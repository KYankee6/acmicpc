#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int left = 0;
    int right = 0;
    for (int i = 0; i<s.size()/2; i++){
        left +=s[i]-'0';
    }
    for(int i=(s.size()/2); i<s.size(); i++){
        right += s[i]-'0';
    }
    if(left==right)
        cout<<"LUCKY";
    else
        cout<<"READY";
}