#include <bits/stdc++.h>
#define pll pair<int, int>
using namespace std;

class cmp
{
public:
    bool operator()(pair<int, int> pq1, pair<int, int> pq2)
    {
        if (pq1.first == pq2.first)
        {
            // priority_queue는 오른쪽이 기준이기 때문에 second 오름차순 정렬
            return pq1.second > pq2.second;
        }
        else
        {
            // priority_queue는 오른쪽이 기준이기 때문에 first 오름차순 정렬
            return pq1.first < pq2.first;
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    vector<long> answers;
    for (int w = 0; w < T; w++)
    {
        long ac = 0;
        int num = 0;
        int day;
        cin >> day;
        vector<int> stock_prices(day, 0);
        priority_queue<pll, vector<pll>, cmp> pq;
        for (int i = 0; i < day; i++)
        {
            cin >> stock_prices[i];
            pq.push({stock_prices[i], i});
        }


        for (int i = 0; i < stock_prices.size(); i++)
        {
            int top = pq.top().first;
            int idx = pq.top().second;
            while (!pq.empty())
            {
                if (idx < i)
                {
                    pq.pop();
                    top = pq.top().first;
                    idx = pq.top().second;
                }
                else
                    break;
            }
            if (stock_prices[i] != top)
            {
                num++;
                ac -= stock_prices[i];
            }
            else
            {
                pq.pop();
                if (num > 0)
                {
                    ac += stock_prices[i] * num;
                    num = 0;
                }
            }
        }
        cout << ac << "\n";
    }
    return 0;
}