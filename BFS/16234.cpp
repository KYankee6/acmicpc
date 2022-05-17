// https://www.acmicpc.net/problem/16234
// 2022-05-18 03:05:38
// 3년전에 ㅂ풀었따는데
// 어.. 유니온 파인드 문제? 같지 않나 싶은데 이걸 3년전에 어케..?
// 유파로도 풀수 있을것같은데
// 기본적으론 BFS다.

// 내가 시험장에 있다면 어떤 선택을 할까?
// 유파로 해보고 bfs도 해보자.. 일단 유파가 짧을것 같으니 유파로

// 2022-05-18 04:30:42 ac
// 40분 제한 문제를 한시간 반만에..? 어지럽다.
// 하지만 이차원 ->일차원으로 생각하는 능력을 기를 수 있었다.
// 아니 근데 이걸 3년전에 풀수 있었다고? 말도 안되는것 같은데..
// bfs가 더 짧다
// bfs가 더 빠르다
// bfs로 할걸

#include <bits/stdc++.h>
using namespace std;

int N, L, R;
vector<int> parent;
vector<int> people_cnt;

vector<int> dx;
bool in_range(int x)
{
    return x >= 0 && x < N * N;
}

int get_root(int x)
{
    if (parent[x] == x)
        return x;
    else
        return parent[x] = get_root(parent[x]);
}

void union_parent(int a, int b)
{
    a = get_root(a);
    b = get_root(b);
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

bool is_unioned(int a, int b)
{
    return get_root(a) == get_root(b);
}

void set_people()
{

    map<int, vector<int>> unioned;
    for (int i = 0; i < parent.size(); i++)
    {
        if (get_root(i) == i)
        {
            unioned[i].push_back(i);
        }
        else
        {
            unioned[get_root(i)].push_back(i);
        }
    }
    for (auto m : unioned)
    {
        if (m.second.size() == 1)
            continue;
        int sum = 0;

        for (auto e : m.second)
        {
            sum += people_cnt[e];
        }
        for (auto e : m.second)
        {
            people_cnt[e] = sum / m.second.size();
        }
    }
    iota(parent.begin(), parent.end(), 0);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> L >> R;
    int answer = 0;

    dx.push_back(N);
    dx.push_back(-N);
    dx.push_back(1);
    dx.push_back(-1);
    parent.resize(N * N, 0);
    people_cnt.resize(N * N, 0);
    iota(parent.begin(), parent.end(), 0);
    for (int i = 0; i < N * N; i++)
    {
        cin >> people_cnt[i];
    }
    while (true)
    {
        bool is_open = false;
        for (int i = 0; i < N * N; i++)
        {
            for (int j = 0; j < 4; j++)
            {

                int adj = i + dx[j];

                if (j == 2 && i % N == N - 1)
                    continue;
                if (j == 3 && i % N == 0)
                    continue;

                if (in_range(adj) && !is_unioned(i, adj) && (abs(people_cnt[i] - people_cnt[adj]) >= L && abs(people_cnt[i] - people_cnt[adj]) <= R))
                {
                    union_parent(i, adj);
                    is_open = true;
                }
            }
        }
        if (!is_open)
            break;
        answer++;
        set_people();
    }
    cout << answer;
    return 0;
}