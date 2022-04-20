
// 2022-04-20 00:00:02 문제 이해
// 2022-04-20 00:06:54 문제풀이 시작
// enemy 객체, archer 객체
// vector<enemy> x, y forward()
// vector<archer> x, y shoot()
// game객체는 없어도 되지 않을까 ? 너무복잡한거같은데

// 2022-04-20 03:08:12  3시간 걸림 너무 오래 걸림 ㅠ
// bfs인데 자꾸 이상한 map으로 iteration 돌리느라 오래걸림
// 다행이도, 로직에 큰 문제는 없어서 예외처리를 안해도 됐었나봄
// 문제 이해도 처음에 잘못함. 
// 객체 만든다고 쌩쇼 +1
// 문제 이해에 시간을 좀더 투자해도 좋을 것 같다(1시간 기준이므로 <10min? 어떨까)



// bfs, dfs 시간 복잡도 계산 하는 방법을 잘 모르겠음
#include <bits/stdc++.h>

using namespace std;
int N, M, D;

int cal_distance(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

bool range_check(int x, int y)
{
    return x >= 0 && y >= 0 && x < N && y < M;
}

vector<pair<int, int>> get_range(int cur_y, vector<vector<int>> &game)
{
    vector<vector<bool>> visited(16, vector<bool>(16,false));
    vector<pair<int, int>> range;
    queue<pair<int, int>> q;
    int walker = 0;
    int x = N;
    int y = cur_y;
    int dx[3] = {0, 0, -1};
    int dy[3] = {-1, 1, 0};
    q.push({x, y});
    visited[x][y]=true;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int cur_x = cur.first;
        int cur_y = cur.second;
        for (int i = 0; i < 3; i++)
        {
            int px = cur_x + dx[i];
            int py = cur_y + dy[i];
            if (range_check(px, py) && cal_distance(px, py, x, y) <= D && !visited[px][py])
            {
                visited[px][py]=true;
                if(game[px][py]==1) range.push_back({px, py});
                q.push({px,py});
            }
        }
    }

    return range;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M >> D;
    vector<vector<int>> og_game(N, vector<int>(M, 0));
    map<pair<int, int>, int> og_enemies;
    int answer = -1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> og_game[i][j];
            if (og_game[i][j] == 1)
                og_enemies[{i, j}] = 1;
        }
    }
    vector<bool> archer_pos(M, false);
    for (int i = 0; i < 3; i++)
        archer_pos[i] = true;
    do
    {
        vector<vector<int>> game = og_game;
        int first_row = 0;
        int cur_game_score = 0;
        while (true)
        {
            bool game_over = true;
            vector<pair<int, int>> archer_range_getter;
            map<pair<int, int>, int> hit_enemies;
            for (int i = 0; i < M; i++)
            {
                if (archer_pos[i])
                {
                    archer_range_getter = (get_range(i, game));
                    int hit_x = 32;
                    int hit_y = 32;
                    int hit_d = 99;
                    bool is_hit = false;
                    for (int j = 0; j < archer_range_getter.size(); j++)
                    {
                        int px = archer_range_getter[j].first;
                        int py = archer_range_getter[j].second;
                        if (hit_d == cal_distance(N, i, px, py))
                        {
                            if (hit_y > py)
                            {
                                hit_x = px;
                                hit_y = py;
                                is_hit = true;
                            }
                        }
                        else
                        {
                            if (hit_d > cal_distance(N, i, px, py))
                            {
                                hit_x = px;
                                hit_y = py;
                                hit_d = cal_distance(N, i, px, py);
                                is_hit = true;
                            }
                        };
                    }
                    if (is_hit)
                        hit_enemies[{hit_x, hit_y}] = 1;
                }
            }
            for (const auto &key : hit_enemies)
            {
                int key_x = key.first.first;
                int key_y = key.first.second;
                game[key_x][key_y] = 0;
                cur_game_score++;
            }
            for (int i = N - 1; i > first_row; i--)
            {
                for (int j = 0; j < M; j++)
                {
                    game[i][j] = game[i - 1][j];
                    if (game[i][j] == 1)
                        game_over = false;
                }
            }
            for (int j = 0; j < M; j++)
            {
                game[first_row][j] = 0;
            }
            first_row++;
            if (game_over)
                break;
        }
        answer = max(answer, cur_game_score);
    } while (prev_permutation(archer_pos.begin(), archer_pos.end()));
    cout << answer;
}