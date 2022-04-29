// 2022-04-29 19:41:28 이해 시작
// 치킨 배달
// 현재 치킨 집이 몇개인지 저장
// 100*100*13 벡터를 생성
// 각 "집" 마다 "치킨 집"과의 갖는 거리 저장
// 이후 조합을 이용하여 치킨 집 폐업
// 이후, 폐업된 치킨 집이면 무시하면서
// 현재 좌표의 최소 치킨 거리 값을 가지는 거리를 모두 더하기
// 0은 빈집 1은 가정집 2는 치킨집
// 모두 순회하며 최소 치킨집을 찾음

// 최대 M개라는 조건이 있으므로, for문 사용 필요.

// 사용되는 변수들
// int chik_cnt
// vector<vector<vector<int>>>(N,vector<vector<int>(N,vector<int>(chik_cnt,0))) chiken_distance;
// vector<bool> comb(chik_place,false);

// 2022-04-29 19:44:37 구현시작
// 2022-04-29 20:02:26 구현 완료 다만 시간 초과가 날수도 있다고 생각.
// 조합(2^13 = 8000 * 100 * 100 * 13)
// 2022-04-29 20:19:49 AC

#include <bits/stdc++.h>
using namespace std;

void cal_chik_distance(int N, vector<vector<int>> &graph, vector<vector<vector<int>>> &cd, map<pair<int, int>, int> &cp)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int walk = 0;
            if (graph[i][j] == 1)
            {
                for (auto e : cp)
                {
                    cd[i][j][walk++] = abs(i - e.first.first) + abs(j - e.first.second);
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int answer = INT_MAX;

    int N, M;
    int chik_cnt = 0;
    cin >> N >> M;

    vector<vector<int>> graph(N, vector<int>(N, 0));
    vector<vector<vector<int>>> chiken_distance;
    map<pair<int, int>, int> chik_pos;
    vector<bool> comb;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 2)
            {
                chik_pos[{i, j}] = 1;
                chik_cnt++;
            }
        }
    }
    chiken_distance.resize(N, vector<vector<int>>(N, vector<int>(chik_cnt, 0)));
    comb.resize(chik_cnt, false);
    cal_chik_distance(N, graph, chiken_distance, chik_pos);
    for (int r = 0; r < M; r++)
    {
        comb[r] = true;
        do
        {
            int result = 0;
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (graph[i][j] == 1)
                    {
                        int min = 201;
                        for (int k = 0; k < chik_cnt; k++)
                        {
                            if (comb[k] && min > chiken_distance[i][j][k])
                            {
                                min = chiken_distance[i][j][k];
                            }
                        }
                        if (min != 201)
                            result += min;
                    }
                }
            }
            answer = min(answer, result);
        } while (prev_permutation(comb.begin(), comb.end()));
    }
    cout << answer;
}
