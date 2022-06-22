#include <bits/stdc++.h>
#define DIV 1000000007
typedef long long ll;
using namespace std;

int N, M, K;
vector<ll> tree;
vector<ll> arr;

ll init(int node, int start, int end)
{
    if (start == end)
    {
        return tree[node] = arr[start];
    }
    int mid = (start + end) / 2;
    return tree[node] = (init(node * 2, start, mid) * init(node * 2 + 1, mid + 1, end)) % DIV;
}
void update(int node, int start, int end, int idx, ll in)
{
    if (idx > end || idx < start)
    {
        return;
    }
    if (start == end)
    {
        tree[node] = in;
        arr[idx] = in;
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, idx, in);
    update(node * 2 + 1, mid + 1, end, idx, in);
    tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % DIV;
}
ll query(int node, int start, int end, int left, int right)
{
    if (end < left || right < start)
    {
        return 1L;
    }
    if (left <= start && end <= right)
    {
        return tree[node] % DIV;
    }
    int mid = (start + end) / 2;

    return (query(node * 2, start, mid, left, right) * query(node * 2 + 1, mid + 1, end, left, right)) % DIV;
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
            ll num, in;
            cin >> idx >> in;
            idx--;
            update(1, 0, N - 1, idx, in);
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