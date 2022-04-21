// 2022-04-21 19:51:39
// 비트마스킹 연습 문제.
// 어찌된게 알고리즘 하나 푸는거는 그 방법만 알면되는데
// 알고리즘 + 알고리즘으로 가면 난이도가 지수적으로 상승하는것 같다.
// 성장계단의 역치에 왔다고 생각한다.

// N<=20, 각자의 값이 100,000이기에 약 8MB로 2,000,000의 수를 비트로 마스킹할 수 있다.
// 그렇다면 모든 수를 일일히 더하는것은 어떻게 해야할까? dfs? bfs? dfs가 약하니까 dfs로 해보자.

#include <bits/stdc++.h>
#define MAX_N 2000000
using namespace std;

vector<bool> answer(MAX_N+1, false);
vector<int> train;

void dfs(int idx, int cur, vector<bool> visited)
{
    answer[cur] = true;
    visited[idx]=true;
    for (int i = 0; i < train.size(); i++)
    {
        if (!visited[i] && train[i]+cur<=MAX_N && answer[train[i]+cur]!=true){
            dfs(i, train[i] + cur, visited);
            visited[i]=false;
        }
    }
}
int main()
{
    int N;
    cin >> N;
    train.resize(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> train[i];
    }

    for (int i = 0; i < N; i++)
    {
        vector<bool> visited(N,false);
        dfs(i, train[i], visited);
    }
    for(int i=1; i<answer.size(); i++){
        if(!answer[i]){
            cout<<i;
            break;
        }
    }
    return 0;
}