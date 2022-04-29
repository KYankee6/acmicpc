// 2022-04-28 16:45 연구소  시간체크 시작
// 목표는 5시 30분까지 구현 및 AC받기

// 1. bfs with parameter -> spread로 지금 check하는게 벽의 개수인지, 바이러스를 퍼트리는 것인지 확인
// 2. 3중 for문으로 벽세우기
// 2-1. 벽이 3개라면 바이러스 퍼트리기 시작.
// 3. 바이러스를 다 퍼트리고 난뒤, 안전공간 세기 시작

// 2022-04-28 17:09:16 구현 완료
// 2022-04-28 17:11:54 디버깅
// 2022-04-28 17:30:46 15분만더..
// 2022-04-28 17:35:33 dx dy를 잘못설정한새1끼가 있따?
// AC 인데 왜 AC인지 모르겠다데스
// 소요시간 1시간
// 풀어본적도 없는 골드 1과 풀어봤던 골드 5를 푸는데 똑같은 시간이 걸린다면
// 도대체 티어 제도가 무슨 의미가 있을까
// 나는 사실 실버 구현/DP도 못풀것같다
// 2년전 이문제는 어떻게 푼걸까..
// 오우 심지어 C문법이보인다
#include <bits/stdc++.h>
#define in_range(x, y) x >= 0 && y >= 0 && x < N &&y < M
using namespace std;

int N, M;
int answer = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<vector<int>> graph;

int bfs(pair<int, int> init, int spread, vector<vector<int>> &wall_graph, vector<vector<bool>> visited)
{
    int result = 0;
    queue<pair<int, int>> q;
    q.push(init);
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int cur_x = cur.first;
        int cur_y = cur.second;
        if (spread == 2)
            wall_graph[cur_x][cur_y] = 2;
        else
            result++;
        visited[cur_x][cur_y] = true;
        for (int i = 0; i < 4; i++)
        {
            int px = cur_x + dx[i];
            int py = cur_y + dy[i];
            if (in_range(px, py) && !visited[px][py] && wall_graph[px][py] == 0)
            {
                q.push({px, py});
                visited[px][py] = true;
            }
        }
    }
    return result;
}

void dfs(int wall_cnt, int x, int y)
{
    if (wall_cnt == 3)
    {
        int result = 0;
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        vector<vector<int>> wall_graph = graph;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (graph[i][j] == 2)
                    bfs({i, j}, 2, wall_graph, visited);
            }
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (wall_graph[i][j] == 0)
                {
                    result++;
                }
            }
        }
        answer = max(result, answer);
        return;
    }
    int px = x;
    int py = y;
    while (true)
    {
        if (graph[px][py] == 0)
        {
            graph[px][py] = 1;
            dfs(wall_cnt + 1, px, py);
            graph[px][py] = 0;
        }
        py++;
        if (py == M)
        {
            py = 0;
            px++;
        }
        if (px == N)
            return;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    graph.resize(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> graph[i][j];
        }
    }
    dfs(0, 0, 0);
    cout << answer;
}