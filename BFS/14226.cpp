#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int S;

bool boundary_check(int cur)
{
    return cur >= 0 && cur <= 1000;
}

void bfs()
{
    vector<vector<bool>> visited(1001,vector<bool>(1001,0));     // visited[time][clipboard]=;
    queue<tuple<int, int, int>> q; // 1 -> display, 2-> clipboard, 3-> time
    q.push(make_tuple(1,0,0));
    visited[1][0] = true;
    while (!q.empty())
    {
        int dp = get<0>(q.front());
        int cb = get<1>(q.front());
        int t = get<2>(q.front());
        q.pop();
        if(dp == S){
            cout<<t;
            return;
        }
        if(boundary_check(dp) && !visited[dp][dp]){
            visited[dp][dp]=true;
            q.push({dp,dp,t+1});
        }
        if(boundary_check(dp-1) && !visited[dp-1][cb]){
            visited[dp-1][cb]=true;
            q.push({dp-1,cb,t+1});
        }
        if(boundary_check(dp+cb) && !visited[dp+cb][cb]){
            visited[dp+cb][cb]=true;
            q.push({dp+cb,cb,t+1});
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);

    cin >> S;
    bfs();
}