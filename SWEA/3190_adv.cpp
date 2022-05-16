// https://www.acmicpc.net/problem/3190
// 2022-05-17 02:27:41
// 뱀문제
// 풀어봤던 문제다.. 제발...
// 이번엔 객체를 만들어서 풀어보자!
// 2022-05-17 03:02:51 구현은 일단 완료
// 2022-05-17 03:16:29 ac

// 객체를 사용하는게 훠어어어ㅓ엉어어얼씬 편하다는걸 깨달아따....
// 근데 익숙해져야 한다.
#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int N, K, L;
int answer = 0;
int cur_time = 0;
vector<vector<int>> board;
deque<pair<int, char>> turns;
// direction 0->up, 1-> right ..
struct snake
{
    int x;
    int y;
    int d;

    snake(){};
    snake(int _x, int _y, int _d) : x(_x), y(_y), d(_d){};

    void turn(char next_dir)
    {
        switch (next_dir)
        {
        case 'L':
        {
            this->d--;
            if (d < 0)
                d = 3;
            break;
        }
        case 'D':
        {
            this->d++;
            d = d % 4;
            break;
        }
        }
    }
};

bool in_range(int x, int y)
{
    return x >= 1 && y >= 1 && x <= N && y <= N && board[x][y] != 2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    deque<snake> dq;
    dq.push_back(snake(1, 1, 1));
    board.resize(N + 1, vector<int>(N + 1, 0));
    board[1][1] = 2;
    for (int i = 0; i < K; i++)
    {
        int x, y;
        cin >> x >> y;
        board[x][y] = 1;
    }
    cin >> L;
    for (int i = 0; i < L; i++)
    {
        int a;
        char b;
        cin >> a >> b;
        turns.push_back({a, b});
    }

    while (true)
    {
        snake head = dq[0];
        if (cur_time == turns[0].first)
        {
            head.turn(turns[0].second);
            turns.pop_front();
        }
        int hd = head.d;
        snake next(head.x + dx[hd], head.y + dy[hd], head.d);
        if (!in_range(next.x, next.y))
            break;
        dq.push_front(next);

        if (board[next.x][next.y] != 1)
        {
            int lastx = dq[dq.size() - 1].x;
            int lasty = dq[dq.size() - 1].y;
            board[lastx][lasty] = 0;
            dq.pop_back();
        }
        board[next.x][next.y] = 2;

        cur_time++;
    }
    cout << cur_time + 1;
    return 0;
}