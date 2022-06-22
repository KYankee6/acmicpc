#include <bits/stdc++.h>
#define INF 1000000001
typedef long long ll;
using namespace std;

int N, M;
vector<ll> tree;
vector<ll> arr;
ll init(int node, int start, int end)
{
    if (start == end)
    {
        return tree[node] = arr[start];
    }
    int mid = (start + end) / 2;
    return tree[node] = min(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
}
void update(int node, int start, int end, int idx, int in)
{
    if (idx < start || idx > end)
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
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
// void minQ(int node, int start, int end, int left, int right)
// {
//     if (start > right || end < left)
//         return;

//     if (left <= start && end <= right)
//     {
//         if (start == end && answer > tree[node])
//         {
//             answer = min(answer, tree[node]);
//             return;
//         }
//     }
//     int mid = (start + end) / 2;
//     minQ(node * 2, start, mid, left, right);
//     minQ(node * 2 + 1, mid + 1, end, left, right);
// }
ll minQ(int node, int start, int end, int left, int right)
{
    if (start > right || end < left)
        return INF;
    if (left <= start && end <= right)
    {
        return tree[node];
    }
    int mid = (start + end) / 2;
    return min(minQ(node * 2, start, mid, left, right), minQ(node * 2 + 1, mid + 1, end, left, right));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    arr.resize(N, 0L);
    tree.resize(N * 4, 0L);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    init(1, 0, N - 1);
    for (int i = 0; i < M; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << minQ(1, 0, N - 1, l - 1, r - 1) << "\n";
    }
}