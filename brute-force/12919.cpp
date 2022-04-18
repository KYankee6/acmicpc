#include <bits/stdc++.h>

using namespace std;
string s1 = "";
string s2 = "";
// bool bfs()
// {
//     queue<string> q;
//     q.push(s1);
//     while(!q.empty()){

//         string cur = q.front();
//         q.pop();
//         if(cur.compare(s2)==0){
//             return true;
//         }
//         if(cur.size()+1 <= s2.size()){
//             string rv = cur;
//             q.push(cur+'A');
//             rv+='B';
//             reverse(rv.begin(),rv.end());
//             q.push(rv);
//         }

//     }
//     return false;
// }
bool answer = false;
void dfs(string cur)
{
    string copy = cur;
    if (cur.size() < s1.size())
        return;
    if (cur.compare(s1) == 0)
    {
        answer = true;
        return;
    }
    if (*(cur.end()-1) == 'A')
    {
        cur.erase(cur.end() - 1);
        dfs(cur);
    }
    if (copy[0] == 'B')
    {
        reverse(copy.begin(), copy.end());
        copy.erase(copy.end() - 1);
        dfs(copy);
    }
}

int main()
{
    cin >> s1 >> s2;
    dfs(s2);
    if (answer)
        cout << 1;
    else
        cout << 0;
}