#include <bits/stdc++.h>
using namespace std;

struct pos
{
    int cost;
    int x;
    int y;

    pos();
    pos(int _cost, int _x, int _y) : cost(_cost), x(_x), y(_y){};
};

bool asc_pos(const pos &p1, const pos &p2)
{
    return p1.cost < p2.cost;
}
bool desc_pos(const pos &p1, const pos &p2)
{
    return p1.cost > p2.cost;
}
vector<int> parent;

int get_root(int x)
{
    if (x == parent[x])
        return parent[x];
    else
        return parent[x] = get_root(x);
}

void set_union(int x, int y)
{
    int px = get_root(x);
    int py = get_root(y);
    if (px < py)
        parent[py] = px;
    else
        parent[px] = py;
}

int get_mst(vector<pos> &edges)
{
    int result = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        int cost = edges[i].cost;
        int a = edges[i].x;
        int b = edges[i].y;
        if (get_root(a) != get_root(b))
        {
            if (cost == 0)
                result++;
            set_union(a, b);
        }
    }
    return result;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    int min_sum = 0;
    int max_sum = 0;
    cin >> N >> M;
    vector<pos> edges;
    parent.resize(N+1,0);
    iota(parent.begin(), parent.end(), 0);
    for (int i = 0; i < M+1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, a, b});
    }
    sort(edges.begin(), edges.end(), asc_pos);
    min_sum = get_mst(edges);
    min_sum *= min_sum;
    iota(parent.begin(), parent.end(), 0);
    sort(edges.begin(), edges.end(), desc_pos);
    max_sum = get_mst(edges);
    max_sum *= max_sum;
    cout << max_sum - min_sum;
    return 0;
}