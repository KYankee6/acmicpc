// 2022-04-28 00:22:24 문제 이해 시작
// BFS + MST 문제
// 먼저 BFS를 사용하여 섬들을 분류한다 1~N(N<=6)
// 이용되는 함수
// bfs(), island_number, bfs_visited, bfsq

// 이후 MST를 위하여 간선들을 제작한다.
// 2차원 for문을 돌면서 섬과 섬 사이의 최소 거리를 찾아낸다.

// 섬과 섬 사이의 최소거리를 찾아냈다면, 간선을 그래프화 시킨후 크루스칼 알고리즘을 적용하자
// 함수
// find, union_parent, get_root

// 이후 parent 순회 -> root가 모두 같은숫자가 아니면 -1
// 아니라면 answer 출력

// 2022-04-28 00:26:17 구현시작
// 2022-04-28 01:04:28 디버깅 시작.
// 예제 모두 AC
// get_root 잘못써서 AC 안되고
// 2022-04-28 01:26:44 AC받음 소요시간 총 1시간
// 코테도 이렇게 나오면 좋겠다..

// N = 100 M = 100 N*M = 10000
// c++ 1억번 연산 == 1초 .
#include <bits/stdc++.h>
#define in_range(x, y) x >= 0 && y >= 0 && x < N &&y < M
using namespace std;

int N, M;
int island_number = 0;

// for mst
vector<tuple<int, int, int>> costs;
vector<vector<int>> mst_graph;
vector<int> parent;
int get_root(int x)
{
    if (parent[x] == x)
        return x;
    return get_root(parent[x]);
}

void union_parent(int a, int b)
{
    int par_a = get_root(a);
    int par_b = get_root(b);
    if (par_a < par_b)
        parent[par_b] = par_a;
    else
        parent[par_a] = par_b;
}

bool find(int a, int b)
{
    return get_root(a) == get_root(b);
}

bool cmp(tuple<int, int, int> t1, tuple<int, int, int> t2)
{
    return get<2>(t1) < get<2>(t2);
}

// for bfs
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<vector<int>> numbered_map;
vector<vector<int>> island_map;
vector<vector<bool>> bfs_visited;
queue<pair<int, int>> bfs_q;
void check_distance(int cur_x, int cur_y)
{
    int cur_island_number = numbered_map[cur_x][cur_y];
    int distance = 0;

    // look for up
    for (int i = cur_x - 1; i >= 0; i--)
    {
        if (numbered_map[i][cur_y] == cur_island_number)
        {
            distance = -1;
            break;
        }
        if (numbered_map[i][cur_y] == INT_MAX)
        {
            distance++;
        }
        else if (numbered_map[i][cur_y] != cur_island_number)
        {
            if (distance == 1)
                break;
            mst_graph[cur_island_number][numbered_map[i][cur_y]] = min(mst_graph[cur_island_number][numbered_map[i][cur_y]], distance);
            mst_graph[numbered_map[i][cur_y]][cur_island_number] = min(mst_graph[cur_island_number][numbered_map[i][cur_y]], distance);
            ;
            break;
        }
    }

    distance = 0;

    // look for down
    for (int i = cur_x + 1; i < N; i++)
    {
        if (numbered_map[i][cur_y] == cur_island_number)
        {
            distance = -1;
            break;
        }
        if (numbered_map[i][cur_y] == INT_MAX)
        {
            distance++;
        }
        else if (numbered_map[i][cur_y] != cur_island_number)
        {
            if (distance == 1)
                break;
            mst_graph[cur_island_number][numbered_map[i][cur_y]] = min(mst_graph[cur_island_number][numbered_map[i][cur_y]], distance);
            ;
            mst_graph[numbered_map[i][cur_y]][cur_island_number] = min(mst_graph[cur_island_number][numbered_map[i][cur_y]], distance);
            ;
            break;
        }
    }

    distance = 0;

    // look for left
    for (int i = cur_y - 1; i >= 0; i--)
    {
        if (numbered_map[cur_x][i] == cur_island_number)
        {
            distance = -1;
            break;
        }
        if (numbered_map[cur_x][i] == INT_MAX)
        {
            distance++;
        }
        else if (numbered_map[cur_x][i] != cur_island_number)
        {
            if (distance == 1)
                break;
            mst_graph[cur_island_number][numbered_map[cur_x][i]] = min(distance, mst_graph[cur_island_number][numbered_map[cur_x][i]]);
            mst_graph[numbered_map[cur_x][i]][cur_island_number] = min(distance, mst_graph[cur_island_number][numbered_map[cur_x][i]]);
            break;
        }
    }

    distance = 0;

    // look for right
    for (int i = cur_y + 1; i < M; i++)
    {
        if (numbered_map[cur_x][i] == cur_island_number)
        {
            distance = -1;
            break;
        }
        if (numbered_map[cur_x][i] == INT_MAX)
        {
            distance++;
        }
        else if (numbered_map[cur_x][i] != cur_island_number)
        {
            if (distance == 1)
                break;
            mst_graph[cur_island_number][numbered_map[cur_x][i]] = min(distance, mst_graph[cur_island_number][numbered_map[cur_x][i]]);
            mst_graph[numbered_map[cur_x][i]][cur_island_number] = min(distance, mst_graph[cur_island_number][numbered_map[cur_x][i]]);
            break;
        }
    }
}
void bfs(int init_x, int init_y)
{
    bfs_q.push({init_x, init_y});
    while (!bfs_q.empty())
    {
        auto cur = bfs_q.front();
        bfs_q.pop();
        bfs_visited[cur.first][cur.second] = true;
        numbered_map[cur.first][cur.second] = island_number;
        for (int i = 0; i < 4; i++)
        {
            int px = cur.first + dx[i];
            int py = cur.second + dy[i];
            if (in_range(px, py) && island_map[px][py] == 1 && !bfs_visited[px][py])
            {
                bfs_visited[px][py] = true;
                bfs_q.push({px, py});
            }
        }
    }
    island_number++;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;

    int answer = 0;

    // bfs
    island_map.resize(N, vector<int>(M, 0));
    numbered_map.resize(N, vector<int>(M, INT_MAX));
    bfs_visited.resize(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> island_map[i][j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (island_map[i][j] == 1 && !bfs_visited[i][j])
            {
                bfs(i, j);
            }
        }
    }

    // mst
    mst_graph.resize(island_number, vector<int>(island_number, INT_MAX)); // mst[cur_island][next_island]=cost
    parent.resize(island_number, 0);
    iota(parent.begin(), parent.end(), 0);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (numbered_map[i][j] != INT_MAX)
            {
                check_distance(i, j);
            }
        }
    }

    for (int i = 0; i < island_number; i++)
    {
        for (int j = 0; j < island_number; j++)
        {
            if (mst_graph[i][j] != INT_MAX)
            {
                costs.push_back({i, j, mst_graph[i][j]});
            }
        }
    }
    sort(costs.begin(), costs.end(), cmp);
    for (int i = 0; i < costs.size(); i++)
    {
        auto cur = costs[i];
        int a = get<0>(cur);
        int b = get<1>(cur);
        int cost = get<2>(cur);
        if (!find(a, b))
        {
            union_parent(a, b);
            answer += cost;
        }
    }
    bool united = true;
    int root = get_root(0);
    for (int i = 1; i < parent.size(); i++)
    {
        if (get_root(i) != root)
        {
            united = false;
            break;
        }
    }
    if (united)
        cout << answer;
    else
        cout << -1;
}
