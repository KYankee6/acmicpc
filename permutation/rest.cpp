#include <bits/stdc++.h>
using namespace std;

int main()
{
    string digits;
    cin >> digits;
    vector<string> answer;
    string result;
    map<int, string> t;
    t[2] = "abc";
    t[3] = "def";
    t[4] = "ghi";
    t[5] = "jkl";
    t[6] = "mno";
    t[7] = "pqrs";
    t[8] = "tuv";
    t[9] = "wxyz";

    int w=0;
    int sum = 0;
    for (int i = 0; i < digits.length(); i++)
    {
        sum += t[digits[i] - '0'].length();
        result+=t[digits[i] - '0'];
    }
    vector<bool> temp(sum,false);
    
    for(int i= 0; i<digits.length(); i++){
        temp[w]=true;
        w+=t[digits[i]-'0'].length();
    }

}