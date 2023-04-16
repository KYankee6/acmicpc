#include <bits/stdc++.h>
using namespace std;
vector<string> cand;
vector<char> sets = {'(', ')'};

bool check(string &s, int &n)
{
    if (s[0] == ')')
        return false;
    int c1 = 0;
    int n1 = n/2;
    int n2 = n/2;
    for (int i = 0; i < s.size(); i++)
    {
        if (c1 < 0)
            return false;
        if (s[i] == '(')
        {
            n1--;
            c1++;
        }
        else
        {
            n2--;
            c1--;
        }
    }
    return (n1 == 0 && n2 == 0 && c1==0) ;
}
void repeatedPerm(string &pts, int depth, int n)
{
    if (depth == n)
    {
        if (check(pts, n))
            cand.push_back(pts);
        return;
    }
    for (int i = 0; i < sets.size(); i++)
    {
        pts += sets[i];
        repeatedPerm(pts, depth + 1, n);
        pts.pop_back();
    }
}
vector<string> generateParenthesis(int n)
{
    string s = "";
    repeatedPerm(s, 0, 2*n);
    return cand;
}

int main()
{
    int n;
    cin >> n;
    vector<string> v = generateParenthesis(n);
    for(auto e : v){
        cout<<e<<endl;
    }
}
