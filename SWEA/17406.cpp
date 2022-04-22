// 2022-04-22 18:51:31 배열돌리기4 문제이해시작
// 2022-04-22 18:53:25 문제 이해는 끝난거 같은데 문제는 구현이 매우 복잡하다는 것.
// 배열돌리기 이전 문제에서 배열을 돌렸으나, 이를 구현하고 오류를 잡는데 꽤나 시간이 걸렸고
// 조금 더 편리한 방법으로 배열을 돌리는 방법을 보았으나,, 방법은 기억이 나는데 구현해보진 않았다.
// 일단 파트를 세개로 나눠보자.
// 1. 배열 돌리기(r,c,s) 함수
// 2. 회전 연산 조합 -> prev_permutation with vector<bool>
// 3. 배열 값 구하는 함수(int cal(vector<vector<int>> graph))

// 가장 큰 문제는 배열 돌리기 함수이다. 이거 예전방식으로 구현하면 최소 2시간 걸릴것같다.. 어떡할까?
// 지금은 연습이니, 편한 배 돌리기를 구현한다고 생각해보고 도전하고 (<30min)
// 안된다면 기존 배열 돌리기로 시도해봐야겠다.

// 시간 복잡도 계산
// 배열 돌리기 조합 O(2^6)
// 돌리는 연산+ 값 구하는 연산 O(2*50*50)
// O(2^7 * 50*50) < O(10^9)이므로 1초안에 가능하다.

// 공간복잡도
// 6! * 50*50 * 4 = 720 *  10000 = 7MB
// 다만 50*50 벡터를 복사해야하는데 이게 좀 부담스러움

// *회전 연산 idx -1 해야함

// 2022-04-22 20:02:16 배열돌리기 프로토타입 작성 완료 테스팅 시작
// 2022-04-22 20:17:19 사이즈 1 성공
// 2022-04-22 20:25:08 사이즈 2 도 성공
// 나머지 연산 시작

// 2022-04-22 20:39:48 nPn 순열 구하는데에 막힘;; 재귀로 구현할 수 있으면 좋으련만 (DFS)

// 2022-04-22 21:00:11 "틀렸습니다" 깨부시작
// 2022-04-22 21:06:58 아니 순열 구하는거에서 틀린거 실화냐 준혁아...진...짜..눈물날려해..ㅠ
#include <bits/stdc++.h>

using namespace std;

int answer = INT_MAX;
int N, M, K;
vector<vector<int>> rotate_pos(K, vector<int>(3, 0));

int sum_2D_vector(vector<vector<int>> &graph)
{
    int result = INT_MAX;
    for (auto v : graph)
    {
        result = min(result, accumulate(v.begin(), v.end(), 0));
    }

    return result;
}

void print_2D_vector(vector<vector<int>> &graph)
{
    cout << "\n==================================\n";
    for (auto v : graph)
    {
        for (auto e : v)
        {
            cout << e << " ";
        }
        cout << "\n";
    }
    cout << "\n==================================\n";

    return;
}

void array_rotator(vector<vector<int>> &graph, int r, int c, int s)
{
    // r,c로부터 4 꼭지점 기준 = s번
    int standard = s;
    while (standard)
    {
        //바깥 -> 안 돌리는 로직

        int dx = r - standard;
        int dy = c - standard;
        int next = graph[dx][dy + 1];
        int prev = graph[dx][dy];
        while (true)
        {
            graph[dx][dy + 1] = prev;
            prev = next;
            dy++;
            if (dy == c + standard)
                break;
            next = graph[dx][dy + 1];
        }

        prev = next;
        next = graph[dx + 1][dy];
        while (true)
        {
            graph[dx + 1][dy] = prev;
            prev = next;
            dx++;
            if (dx == r + standard)
                break;
            next = graph[dx + 1][dy];
        }

        prev = next;
        next = graph[dx][dy - 1];
        while (true)
        {
            graph[dx][dy - 1] = prev;
            prev = next;
            dy--;
            if (dy == c - standard)
                break;
            next = graph[dx][dy - 1];
        }

        prev = next;
        next = graph[dx - 1][dy];
        while (true)
        {
            graph[dx - 1][dy] = prev;
            prev = next;
            dx--;
            if (dx == r - standard)
                break;
            next = graph[dx - 1][dy];
        }
        standard--;
    }
}

void dfs(int depth, int idx, vector<vector<int>> graph, vector<bool> visited)
{
    if (visited[idx])
        return;
    if (depth == K - 1)
    {
        auto v = rotate_pos[idx];
        array_rotator(graph, v[0] - 1, v[1] - 1, v[2]);
        answer = min(sum_2D_vector(graph), answer);
        return;
    }
    visited[idx] = true;
    for (int i = 0; i < K; i++)
    {
        if (!visited[i])
        {
            auto v = rotate_pos[i];
            array_rotator(graph, v[0] - 1, v[1] - 1, v[2]);
            dfs(depth + 1, i, graph, visited);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> K;

    vector<vector<int>> graph(N, vector<int>(M, 0));
    rotate_pos.resize(K, vector<int>(3, 0));

    vector<int> temp(K, 0);
    for (int i = 0; i < K; i++)
    {
        temp[i] = i;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> rotate_pos[i][j];
        }
    }

    vector<bool> visited(K,false);
    dfs(0, 0, graph, visited);
    cout << answer;

    /**
     * @brief 정답 코드
     *
     */
    // do{
    //     vector<vector<int>> copy = graph;
    //     for(int i=0; i<K; i++){
    //         auto v =rotate_pos[temp[i]];
    //         array_rotator(copy,v[0]-1,v[1]-1,v[2]);
    //     }
    //     answer = min(answer, sum_2D_vector(copy));
    // }while(next_permutation(temp.begin(),temp.end()));
    // cout << answer;

    /**
     * @brief for test
     *  임의의 이차원 그래프 만들고 돌리고, 출력할 수 있게한 테스트
     */
    // vector<vector<int>> test = {{1, 2, 3, 4, 5}, {6, 7, 8,9,10}, {11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
    // print_2D_vector(test);
    // array_rotator(test, 2, 2, 2);
}