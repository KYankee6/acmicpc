// MST 연습문제
// MST 문제라는 것을 몰랐을때, MST라고 아는 것도 중요하겠지만
// 문제 이름이.. MST?

// 2022-04-27 18:56:31 크루스칼 알고리즘 선택
// 이유 : '시작점'이 주어지지 않음.
// 크루스칼 알고리즘의 시간 복잡도는 '정렬 방법'에 좌우된다.
// 어차피 min-heap or sort 쓸 거기 때문에 O(ElogE) (O(E)=10^5) 시간 복잡도는 만족한다.
// 다음으로, 공간복잡도도 100KB*4 (유니온 파인드 트리)만족.
// union-find 시간복잡도는 O(1)이라고 한다 (sus-face)

// 2022-04-27 18:59:38 구현시작
// UF 가장 중요한 세가지. find(), get_root(), union_parent()를 기억하자.

// 2022-04-27 19:14:00 AC
// tuple이 아니라 2차원 vector 시도

// 놀랍게도 tuple이 메모리는 반, 시간은 1/4가 나왔다
// ? 어... 어..음? 어.. 이차원 메모리 접근 .. 어... 어..?

#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<tuple<int, int, int>> costs;
int V, E;

bool cmp(tuple<int, int, int> t1, tuple<int, int, int> t2)
{
    return get<2>(t1) < get<2>(t2);
}

int get_root(int cur)
{
    if (parent[cur] == cur)
        return cur;
    return get_root(parent[cur]);
}
void union_parent(int a, int b)
{
    int par_a = get_root(a);
    int par_b = get_root(b);
    if (par_a < par_b)
        parent[par_b] = par_a;
    else
        parent[par_a] = par_b;
}

bool find(int a, int b)
{
    return get_root(a) == get_root(b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int answer=0;

    cin >> V >> E;
    parent.resize(V, 0);
    iota(parent.begin(), parent.end(), 0);
    for (int i = 0; i < E; i++)
    {
        int src, dest, cost;
        cin >> src >> dest >> cost;

        costs.push_back({src-1, dest-1, cost});
    }
    sort(costs.begin(),costs.end(),cmp);
    for(int i=0; i<E; i++){
        auto cur = costs[i];
        int src = get<0>(cur);
        int dest = get<1>(cur);
        int cost = get<2>(cur);
        if(!find(src,dest)){
            union_parent(src,dest);
            answer+=cost;
        }
    }
    tuple<int,int,int> tuple1={1,2,3};
    vector<int> vector1(3,0);
    cout<< sizeof(tuple1)<<endl;
    cout<< sizeof(vector1)<<endl;
}

// #include <bits/stdc++.h>
// using namespace std;

// vector<int> parent;
// vector<vector<int>> costs;
// int V, E;

// bool cmp(vector<int> v1, vector<int> v2)
// {
//     return v1[2] < v2[2];
// }

// int get_root(int cur)
// {
//     if (parent[cur] == cur)
//         return cur;
//     return get_root(parent[cur]);
// }
// void union_parent(int a, int b)
// {
//     int par_a = get_root(a);
//     int par_b = get_root(b);
//     if (par_a < par_b)
//         parent[par_b] = par_a;
//     else
//         parent[par_a] = par_b;
// }

// bool find(int a, int b)
// {
//     return get_root(a) == get_root(b);
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);

//     int answer = 0;

//     cin >> V >> E;
//     parent.resize(V, 0);
//     iota(parent.begin(), parent.end(), 0);
//     for (int i = 0; i < E; i++)
//     {
//         vector<int> cost(3, 0);
//         cin >> cost[0] >> cost[1] >> cost[2];
//         cost[0]--;
//         cost[1]--;
//         costs.push_back(cost);
//     }
//     sort(costs.begin(), costs.end(), cmp);
//     for (int i = 0; i < E; i++)
//     {
//         int src = costs[i][0];
//         int dest = costs[i][1];
//         int cost = costs[i][2];
//         if (!find(src, dest))
//         {
//             union_parent(src, dest);
//             answer += cost;
//         }
//     }
//     cout << answer;
// }