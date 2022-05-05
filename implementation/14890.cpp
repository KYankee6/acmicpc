// 2022-05-05 19:44:02 경사로
// 먼저 2N개의 배열을 빼온다(행,열)
// L을 기준으로 현재 경사로를 놓아야 하는지 확인하는 함수 작성
// 있다면 경사로를 놓는 함수 작성
// 여기서, 경사로를 놓지 못한다면, 그 경사로는 건널수 없다고 표시(배열 생성)
// 그러므로 2중 반복문을 사용하고
// 첫번째는 iter - L 까지 반복
// 두번째는 0부터 L 까지 반복

// 2022-05-05 19:46:40 구현시작
// 1. is_bridgable
// 2. set_bridge

// 2022-05-05 20:04:07 디버깅 시작
// 2022-05-05 21:30:37 AC 총 소모시간 2시간 (중간에 조금 집중 못하기도 했으나 많이 늦었음)
// 문제점 : 무조건 앞의 계단이 더 낮을것이라고 생각하고 접근하다가 많이 깨짐
// 그 후로 신나게 ad-hoc하다가 멘탈 많이 무너짐
// 운 좋게 AC 됐지만 멘탈 잡아야할 듯
#include <bits/stdc++.h>
using namespace std;

int N, L;
int answer = 0;

vector<vector<int>> bridges;
vector<vector<int>> point;
vector<vector<int>> graph;

bool check_crossible(vector<int> &bridge, int idx)
{
    int level = bridge[0];
    for (int i = 0; i < bridge.size()-1; i++)
    {
        if (point[idx][i] == 1)
        {
            level = bridge[i + L];
            i += (L - 1);
            continue;
        }
        if (level != bridge[i+1])
            return false;
    }
    return true;
}

void set_bridge(vector<int> &bridge, int start, int level)
{
    for (int i = start; i < start + L; i++)
    {
        bridge[i] = level;
    }
}

bool is_bridgable(vector<int> &bridge, int idx)
{

    for (int i = 0; i < bridge.size() - L; i++)
    {
        if (bridge[i] != bridge[i + L])
        {
            if (abs(bridge[i] - bridge[i + L]) != 1)
                return false;
            if (bridge[i] > bridge[i + L])
            {
                if (bridge[i] == bridge[i + 1])
                    continue;
                int level = bridge[i + 1];
                for (int j = i + 1; j <= i + L; j++)
                {
                    if (bridge[j] != level)
                        return false;
                }
                for (int j = i + 1; j <= i + L; j++)
                {
                    point[idx][j] = -1;
                }
                point[idx][i] = 1;
                i = i + L - 1;
            }
            else
            {
                if(point[idx][i]==-1)continue;
                for (int j = i; j < i + L; j++)
                {
                    if (bridge[j] != bridge[i])
                        return false;
                }
                point[idx][i] = 1;
                i = i + L - 1;
            }
        }
    }

    return check_crossible(bridge, idx);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> L;
    bridges.resize(2 * N, vector<int>(N, 0));
    point.resize(2 * N, vector<int>(N, 0));
    graph.resize(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> graph[i][j];
        }
        bridges[i] = graph[i];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            bridges[i + N][j] = graph[j][i];
        }
    }
    for (int i = 0; i < 2 * N; i++)
    {
        if (is_bridgable(bridges[i], i))
            answer++;
    }
    cout << answer;
    return 0;
}
