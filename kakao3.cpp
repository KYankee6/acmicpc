#include <bits/stdc++.h>

using namespace std;

bool comp_algo_first(vector<int> &v1, vector<int> &v2)
{
    return v1[2] == v2[2] ? v1[3] > v1[3] : v1[2] > v2[2];
}
bool comp_code_first(vector<int> &v1, vector<int> &v2)
{
    return v1[3] == v2[3] ? v1[2] > v2[2] : v1[3] > v2[3];
}

vector<int> solvable_idx(vector<vector<int>> &problems, int alp, int cop)
{
    vector<int> result;
    for (int i = 0; i < problems.size(); i++)
    {
        if (problems[i][0] <= alp && problems[i][1] <= cop)
        {
            result.push_back(i);
        }
    }
    return result;
}

bool check_problem(vector<int> &problems, int time)
{
    return problems[4] <= time;
}

int solution(int alp, int cop, vector<vector<int>> problems)
{
    int answer = 0;
    int max_cop = -1;
    int max_alp = -1;

    for (int i = 0; i < problems.size(); i++)
    {
        if (max_alp < problems[i][0])
        {
            max_alp = problems[i][0];
        }
        if (max_cop < problems[i][1])
        {
            max_cop = problems[i][1];
        }
    }
    if (alp >= max_alp && cop >= max_cop)
        return 0;
    vector<vector<int>> time_dp(151, vector<int>(151, INT_MAX));
    for (int i = 0; i <= alp; i++)
    {
        for (int j = 0; j <= cop; j++)
        {
            time_dp[i][j] = 0;
        }
    }
    for (int i = alp; i < 150; i++)
    {

        for (int j = cop; j < 150; j++)
        {
                time_dp[i + 1][j] = time_dp[i][j] + 1;
                time_dp[i][j + 1] = time_dp[i][j] + 1;
        }
    }
    for (int i = alp; i <= max_alp; i++)
    {
        for (int j = cop; j <= max_cop; j++)
        {
            vector<int> ns = solvable_idx(problems, i, j);
            for (int k = 0; k < ns.size(); k++)
            {
                int get_alp = problems[ns[k]][2];
                int get_cop = problems[ns[k]][3];
                int cost = problems[ns[k]][4];
                for (int w = 1; w <= 100; w++)
                {
                    if (i + get_alp * w <= max_alp && j + get_cop * w <= max_cop)
                        time_dp[i + get_alp * w][j + get_cop * w] = min(time_dp[i + get_alp * w][j + get_cop * w] + cost * w, (get_alp + get_cop) * w);
                }
            }
        }
    }
    answer = time_dp[max_alp][max_cop];
    return answer;
}

int main()
{
    vector<vector<int>> v = {{10, 15, 2, 1, 2}, {20, 20, 3, 3, 4}};
    cout << solution(10, 10, v);
}