// https://www.acmicpc.net/problem/1715
// 카드 묶음 합치기
// 2022-05-19 14:06:07
// 2022-05-19 14:12:08 AC
// 이런 문제는 조금은 뻔하게 우선순위 큐를 요구하고
// 다른 요구사항이 없었기에 쉬웠다.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int answer=0;
    int N;
    cin>>N;
    priority_queue<int> pq;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        pq.push(-temp);
    }
    while (!pq.empty())
    {
        int cur = -pq.top();
        pq.pop();
        if (pq.empty())
        {
            cout << answer;
            break;
        }
        int next = -pq.top();
        pq.pop();
        pq.push(-(cur + next));
        answer+=cur+next;
    }
    return 0;
}