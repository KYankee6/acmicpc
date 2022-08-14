#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    priority_queue<int> pq;
    for (int i = 0; i < N; i++)
    {
        int op;
        cin >> op;
        if (op == 0)
        {
            if (pq.empty())
            {
                cout << 0 << '\n';
            }
            else
            {
                cout << pq.top() << '\n';
     
                pq.pop();
            }
        }
        else
        {
            pq.push(op);
        }
    }
    return 0;
}