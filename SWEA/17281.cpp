// 2022-04-23 14:07:28 문제 이해 끝
// 아마도 순열+구현하는 문제인듯

// 시간복잡도가 8!*50 < 10^last_turn이므로 permutation으로 돌려도 될 것 같다.
// 먼저 v1 = {선수들 능력치};
//      v2 = {선수 뽑는 순서};
// permutation 돌리고 게임 결과 알아내기 하면될것같다.
// 1. 선수들 순번이 들어왔을때 게임 결과를 알아내는 함수
// game(vector<int> roster)

// 2022-04-23 14:11:08 구현 시작
// 2022-04-23 14:49:31 디버깅시작
// 2022-04-23 15:29:29 누가봐도 시간초과날것같은데 어떡하죠
// 2022-04-23 15:37:11 시간초과. 삭제해볼까?
#include <bits/stdc++.h>
#define LAST_TURN 9
using namespace std;

int N;
vector<vector<int>> stat;

pair<int, int> game(vector<int> &roster, int turn) // first point, last next_turn
{
    vector<int> current_base(3, 0);
    int result = 0;
    int out_count = 0;
    int point = 0;
    while (out_count != 3)
    {
        if (turn == LAST_TURN)
            turn = 0;

        int bat_result = roster[turn];
        if (bat_result == 0)
        {
            out_count++;
        }

        else
        {
            for (int i = 2; i >= 0; i--)
            {
                if (current_base[i] == 1)
                {
                    if (bat_result + i >= 3)
                    {
                        result++;
                        current_base[i] = 0;
                    }
                    else
                    {
                        current_base[bat_result + i] = 1;
                        current_base[i] = 0;
                    }
                }

            }
            if (bat_result == 4)
            {
                result++;
            }
            else
            {
                current_base[bat_result-1] = 1;
            }
        }
        // 시간초과
        // else
        // {
        //     for (auto &e : current_base)
        //     {
        //         e += bat_result;
        //     }
        //     current_base.push_back(bat_result);
        // }
        turn++;
    }
    return {result, turn};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int answer = -1;
    cin >> N;
    vector<int> turn_fixer(LAST_TURN - 1, 0);
    stat.resize(N, vector<int>(LAST_TURN, 0));

    for (int i = 1; i <= LAST_TURN - 1; i++)
    {
        turn_fixer[i - 1] = i;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < LAST_TURN; j++)
        {
            cin >> stat[i][j];
        }
    }

    do
    {
        int inning = 0;
        int turn = 0;
        int result = 0;

        while (inning != N)
        {
            int walker = 0;
            vector<int> roster;
            for (int i = 0; i < LAST_TURN; i++)
            {
                if (i == 3)
                {
                    roster.push_back(stat[inning][0]);
                }
                else
                {
                    roster.push_back(stat[inning][turn_fixer[walker]]);
                    walker++;
                }
            }

            auto game_result = game(roster, turn);
            result += game_result.first;
            turn = game_result.second;
            inning++;
        }
        answer = max(answer, result);
    } while (next_permutation(turn_fixer.begin(), turn_fixer.end()));
    cout << answer;
    return 0;
}