// 2022-04-26 16:41:35 문제 이해 시작
// deque을 사용해보자. why? 머리 앞을 push_front 하는 경우가 생길것 같다.
// operation(N초후 방향전환)은 queue로 구현하자. while(!q.empty()){second++;}
// 뱀은 deque로 구현하자. pair<int,int> dq; ={현재 좌표들};
// 뱀이 이동/방향전환 할때, 앞머리만 바뀌면된다, 그 이후 녀석들은 앞머리만 따라가면됨
// 1. 사과 x -> push_front. pop_back()
// 2. 사과 o -> push_front only

// 자기 자신과 부딪히는 경우는 어떡하나?
// graph에 뱀정보도 입력할까? -> 하자

// 2022-04-26 16:49:07 구현시작
// 2022-04-26 17:25:52 디버깅 시작
// 2022-04-26 17:42:44 고질적인거 같은데 변수 접근 시 에러나고있음 2차원배열에 nx, ny 접근하는데 값을 제대로 못받는듯

// 2022-04-26 18:05:14 AC
// 원콤남 미쳤다 미쳤어 ㅋㅋㅋㅋㅋㅋㅋㅋㅋ
#include <bits/stdc++.h>

using namespace std;

int N, K, L;
vector<vector<int>> graph;
queue<pair<int, char>> ops;
deque<tuple<int, int, int>> snake; // x, y , dir
                                   //  dir 0-> top, 1-> right, 2-> down, 3-> left
                                   // L ->0, R ->1

bool in_range(int x, int y)
{
    return (x >= 0 && y >= 0 && x < N && y < N) && (graph[x][y] == 0 || graph[x][y] == 1);
}

tuple<int, int, int> get_next_pos(tuple<int, int, int> &cur_pos, int change)
{
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int cur_x = get<0>(cur_pos);
    int cur_y = get<1>(cur_pos);
    int cur_dir = get<2>(cur_pos);

    vector<int> next_dirs = {0, 1, 2, 3};
    if (change == -1)
    {
        // do nothing
    }
    else if (change == 0)
    {
        rotate(next_dirs.rbegin(), next_dirs.rbegin() + 1, next_dirs.rend());
    }
    else
    {
        rotate(next_dirs.begin(), next_dirs.begin() + 1, next_dirs.end());
    }
    int next_dir = next_dirs[cur_dir];
    int px = cur_x + dx[next_dir];
    int py = cur_y + dy[next_dir];
    return {px, py, next_dir};
}

bool forward(int change)
{
    auto cur_head = snake[0];
    auto next_pos = get_next_pos(snake[0], change);
    int nx = get<0>(next_pos);
    int ny = get<1>(next_pos);
    if (!in_range(nx, ny)) // 자신에게 닿거나, 벽을 넘어간경우
        return false;
    snake.push_front(next_pos); // 일단 머리는 전진
    if (graph[nx][ny] != 1)     //사과 먹은게 아니면 꼬리 pop
    {
        auto tail = *(snake.end() - 1);
        snake.pop_back();
        graph[get<0>(tail)][get<1>(tail)] = 0;
    }
    graph[nx][ny] = 2;

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int answer = 0;
    cin >> N >> K;
    graph.resize(N, vector<int>(N, 0));

    graph[0][0] = 2;
    snake.push_back({0, 0, 1});
    for (int i = 0; i < K; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[--x][--y] = 1; // 1: apple, 2: snake, 3: empty
    }
    cin >> L;
    for (int i = 0; i < L; i++)
    {
        int sec;
        char op;
        cin >> sec >> op;
        ops.push({sec, op});
    }
    while (true)
    {
        if (!ops.empty())
        {
            auto cur = ops.front();
            if (cur.first == answer)
            {
                int next = cur.second == 'L' ? 0 : 1;
                if (!forward(next))
                    break;

                ops.pop();
            }
            else
            {
                if (!forward(-1))
                    break;
            }
        }
        else
        {
            if (!forward(-1))
                break;
        }
        answer++;
    }
    cout << answer + 1;
}
