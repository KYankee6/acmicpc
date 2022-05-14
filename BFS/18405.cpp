// 2022-05-14 20:45:48
// 경쟁적 전염
// priority queue를 사용하자.

// 1. 먼저 pq에 바이러스를 tuple로 담는다. 첫번째가 cost다.
// 2. bfs를 돌린다. S초 이후를 어떻게 구현할 것인가?
// 2-1 vector를 이용해서 임의로 저장만 한다.
// 2-2 counter를 이용해서 counter==0이 되면 현재 사이즈를 또 다시 담는다(한 세트가 끝났다는 뜻이므로)
// 2-2-1 counter와 int time=0;으로 시간초 S를 셀 수 있다.
// 2-2-2 S+1초라면 bfs를 멈춘다.
// 2번의 방법으로 구현 시작
// pq로 하면 무조건 1만 하기 시작한다
// 2022-05-14 20:50:23
// deque을 쓰자 걍..
// 2022-05-14 21:15:32 AC
// 이 문제의 시간 복잡도는 어떻게 구해야 할까?
// sort를 쓰긴 했지만 어떻게 자신있게 TLE 안난다고 할 수 있을까?
#include <bits/stdc++.h>
using namespace std;

int N, K, S, X, Y; // S 초 이후, X,Y 위치
vector<vector<int>> graph;
deque<tuple<int, int, int>> dq;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool in_range(int x, int y)
{
    return x >= 1 && y >= 1 && x <= N && y <= N;
}

void bfs()
{
    int time = 0;
    int set_cnt = dq.size();
    sort(dq.begin(),dq.end());
    while (!dq.empty())
    {
        if (set_cnt == 0)
        {
            time++;
            set_cnt = dq.size();
            if (time == S)
            {
                return;
            }
            sort(dq.begin(),dq.end());
        }
        set_cnt--;
        int v_num = get<0>(dq[0]);
        int cur_x = get<1>(dq[0]);
        int cur_y = get<2>(dq[0]);
        dq.pop_front();
        for (int i = 0; i < 4; i++)
        {
            int px = dx[i] + cur_x;
            int py = dy[i] + cur_y;
            if (in_range(px, py) && graph[px][py] == 0)
            {
                dq.push_back(make_tuple(v_num, px, py));
                graph[px][py] = v_num;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    graph.resize(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] != 0)
            {
                dq.push_back(make_tuple(graph[i][j], i, j));
            }
        }
    }
    cin >> S >> X >> Y;
    if(S!=0)
        bfs();
    cout<<graph[X][Y];
    return 0;
}