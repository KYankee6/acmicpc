// https://www.acmicpc.net/problem/15686
// 치킨 배달
// 2022-05-17 05:35:03


// 2022-05-17 05:52:02 AC
// 상태도 메롱인데 풀었던건 다시 풀수 있구나
// 다행이다..
#include <bits/stdc++.h>

using namespace std;

int get_dist(pair<int, int> &pos1, pair<int, int> pos2)
{
    return abs(pos1.first - pos2.first) + abs(pos1.second - pos2.second);
}

int N, M;
vector<vector<int>> graph;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    int chik_cnt = 0;
    int answer =INT_MAX;
    graph.resize(N, vector<int>(N, 0));
    vector<pair<int, int>> chiken_house;
    vector<bool> temp;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 2)
            {
                chiken_house.push_back({i, j});
                chik_cnt++;
            }
        }
    }
    temp.resize(chik_cnt, false);
    for (int r = 0; r < M; r++)
    {
        temp[r] = true;
        do
        {
            int result =0;
            vector<pair<int, int>> survive_place;
            for (int i = 0; i < chik_cnt; i++)
            {
                if (temp[i] == true)
                { // 살아남은 치킨집
                    survive_place.push_back(chiken_house[i]);
                }
            }
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    int min_dist = INT_MAX;
                    if (graph[i][j] == 1)
                    {
                        for (int k = 0; k < survive_place.size(); k++)
                        {
                            min_dist = min(min_dist, get_dist(survive_place[k],{i,j}));
                        }
                        result+=min_dist;
                    }
                }
            }
            answer = min(answer,result);
        } while (prev_permutation(temp.begin(), temp.end()));
    }
    cout<<answer;
    return 0;
}