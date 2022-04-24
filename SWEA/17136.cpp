// 2022-04-20 17:45:41 문제 보기 시작
// 2022-04-20 17:54:51 이어폰 놓고와서 걸어다니면서 문제 풀이법 생각해냄 (ㄹㅈㄷ)
// 맵 받고, 맵 순회하면서 BFS로 pair<int,int>로 걔네들 받음
// 함수 하나 만들어서 (bool size_check_by(int N)) 체크(큰거부터 해야함)
// 4x4 되는지 확인 (전체) -> 3x3 ...
// 가보자 !

// 2022-04-20 17:56:00 구현 시작

// 2022-04-20 19:27:15 색종이 남은 개수를 사용하는 방식에서 뭔가 크게 잘못됐다..
// 2022-04-20 19:35:56 그리디하게 풀면 (큰 종이부터 사용하면) 접근 불가능하다..

// 2022-04-24 14:06:13 다시 도전 시작
// 2022-04-24 14:40:13 dfs로 다시 도전 시작
// 2022-04-24 15:15:26 디버깅 시작

#include <bits/stdc++.h>
#define N 10
using namespace std;
vector<vector<int>> graph;
vector<vector<int>> candidate(N, vector<int>(N, 0));
vector<int> color_paper = {0, 5, 5, 5, 5, 5};

bool valid_bit = false;
int answer = INT_MAX;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool is_in_range(int x, int y)
{
    return x >= 0 && y >= 0 && x < N && y < N;
}

void print_canvas(int canv_size, int src_x, int src_y, int bit)
{
    for (int i = src_x; i < src_x + canv_size; i++)
    {
        for (int j = src_y; j < src_y + canv_size; j++)
        {
            graph[i][j] = bit;
        }
    }
}

bool size_checker(int canv_size, int src_x, int src_y)
{
    int result = 0;
    for (int i = 0; i < canv_size; i++)
    {
        for (int j = 0; j < canv_size; j++)
        {
            int px = src_x + i;
            int py = src_y + j;
            if (is_in_range(px, py) && graph[px][py] == 1)
                result++;
            else
            {
                return false;
            }
        }
    }

    if (result == canv_size * canv_size)
        return true;

    else
        return false;
}

void dfs(int cur_x, int cur_y, int left_target, int used_paper)
{
    if(answer <= used_paper) return;
    if (left_target == 0)
    {
        valid_bit = true;
        answer = min(answer, used_paper);
        return;
    }
    for (int i = cur_x; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == cur_x && j==0)
                j += cur_y;

            if (graph[i][j] == 0)
                continue;
            for (int k = candidate[i][j]; k >= 1; k--)
            {
                if ( graph[i][j] == 1 && color_paper[k] != 0  && size_checker(k, i, j))
                {
                    print_canvas(k, i, j, 0);
                    color_paper[k]--;
                    dfs(i, j, left_target - (k * k), used_paper + 1);
                    print_canvas(k, i, j, 1);
                    color_paper[k]++;
                }
            }
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int left_target = 0;
    graph.resize(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 1)
                left_target++;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 5; k >= 1; k--)
            {
                if (graph[i][j] == 1)
                {
                    if (size_checker(k, i, j))
                    {
                        candidate[i][j] = k;
                        break;
                    }
                }
            }
        }
    }

    if (left_target == 0)
    {
        cout << 0;
        return 0;
    }

    dfs(0, 0, left_target, 0);

    if (valid_bit)
        cout << answer;
    else
        cout << -1;
    return 0;
}
