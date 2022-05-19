// https://www.acmicpc.net/problem/10825
// 국영수
// 2022-05-19 08:04:21

// 의도적 수련
// 1. 커스텀 구조체 + 맵 sort
// 2. 커스텀 구조체 + 맵 + CMP sort
// 왜 안될까 ㅠ,ㅠ

// const 붙이는 생활화를 합시다.
// struct 밖에 cmp 만드는게 더 빨랐다.(의외였다.)
#include <bits/stdc++.h>

using namespace std;

struct obj
{
    string name;
    vector<int> scores;

    obj(){};
    obj(string _name, vector<int> _scores) : name(_name), scores(_scores){};

    bool operator<(const obj &other)
    {
        if (scores[0] != other.scores[0])
        {
            return scores[0] > other.scores[0];
        }
        else if (scores[1] != other.scores[1])
        {
            return scores[1] < other.scores[1];
        }
        else if (scores[2] != other.scores[2])
        {
            return scores[2] > other.scores[2];
        }
        else
        {
            return name < other.name;
        }
    }
};

struct cmp
{
    bool operator()(const obj &o1, const obj &o2)
        const
    {
        if (o1.scores[0] != o2.scores[0])
        {
            return o1.scores[0] > o2.scores[0];
        }
        else if (o1.scores[1] != o2.scores[1])
        {
            return o1.scores[1] < o2.scores[1];
        }
        else if (o1.scores[2] != o2.scores[2])
        {
            return o1.scores[2] > o2.scores[2];
        }
        else
        {
            return o1.name < o2.name;
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    set<obj, cmp> obj_set;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string s;
        int a, b, c;
        cin >> s >> a >> b >> c;
        obj_set.insert({s, {a, b, c}});
    }
    for (auto &e : obj_set)
    {
        cout << e.name << "\n";
    }
    return 0;
}