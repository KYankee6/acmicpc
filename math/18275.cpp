#include <bits/stdc++.h>
#define DIV 1000007
using namespace std;

int w, h;
int x, y;
vector<vector<int>> graph;

void find_path(int src_x, int src_y, int dest_x, int dest_y)
{
    int dx = src_x;
    int dy = src_y;
    for (int i = src_x; i  <= dest_x; i++)
    {
        graph[i][src_y] = graph[src_x][src_y];
    }
    for (int i = src_y; i  <= dest_y; i++)
    {
        graph[src_x][i] = graph[src_x][src_y];
    }
    while (dx <= dest_x || dy <= dest_y)
    {
        for (int i = dx; i <= dest_x; i++)
        {
            if (i == 1)
                continue;
            graph[i][dy] = (graph[i - 1][dy] + graph[i][dy - 1]) % DIV;
        }
        for (int i = dy; i <= dest_y; i++)
        {
            if (i == 1)
                continue;
            graph[dx][i] = (graph[dx][i - 1] + graph[dx - 1][i]) % DIV;
        }
        if (dx == dest_x && dy == dest_y)
            break;
        if (dx < dest_x)
            dx++;
        if (dy < dest_y)
            dy++;
    }
}

int main()
{
    cin >> w >> h >> x >> y;
    graph.resize(h + 1, vector<int>(w + 1, 0));
    graph[1][1] = 1;
    find_path(1, 1, y, x);
    find_path(y, x, h, w);
    cout << graph[h][w] % DIV;
    return 0;
}