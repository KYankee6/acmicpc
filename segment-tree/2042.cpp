#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

// int h = (int)ceil(log2(N));
// int treeSize = (1 << (h + 1));
int N, M, K;
vector<ll> arr;
vector<ll> tree;

ll init(int node, int start, int end)
{
    if (start == end)
    {
        return tree[node] = arr[start];
    }
    int mid = (start + end) / 2;

    return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

void update(int node, int start, int end, int idx, ll diff)
{
    if (idx < start || idx > end)
    {
        return;
    }
    tree[node] += diff;
    if (start != end)
    {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, idx, diff);
        update(node * 2 + 1, mid + 1, end, idx, diff);
    }
}

ll query(int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
    {
        return 0L;
    }
    if (left <= start && end <= right)
    {
        return tree[node];
    }

    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> K;
    arr.resize(N);
    tree.resize(N * 4);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    init(1, 0, N - 1);
    for (int i = 0; i < M + K; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int idx;
            ll num, diff;
            cin >> idx >> num;
            idx--;
            diff = (ll)(num - arr[idx]);
            arr[idx] = num;
            update(1, 0, N - 1, idx, diff);
        }
        else
        {
            int left, right;
            cin >> left >> right;
            cout << query(1, 0, N - 1, left - 1, right - 1) << "\n";
        }
    }
    return 0;
}