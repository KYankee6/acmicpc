// // 2022-04-20 17:45:41 문제 보기 시작
// // 2022-04-20 17:54:51 이어폰 놓고와서 걸어다니면서 문제 풀이법 생각해냄 (ㄹㅈㄷ)
// // 맵 받고, 맵 순회하면서 BFS로 pair<int,int>로 걔네들 받음
// // 함수 하나 만들어서 (bool size_check_by(int N)) 체크(큰거부터 해야함)
// // 4x4 되는지 확인 (전체) -> 3x3 ...
// // 가보자 !

// // 2022-04-20 17:56:00 구현 시작

// // 2022-04-20 19:27:15 색종이 남은 개수를 사용하는 방식에서 뭔가 크게 잘못됐다..
// // 2022-04-20 19:35:56 그리디하게 풀면 (큰 종이부터 사용하면) 접근 불가능하다..

// #include <bits/stdc++.h>
// #define N 10
// using namespace std;
// vector<vector<int>> graph;
// vector<int> color_paper = {0, 5, 5, 5, 5, 5};

// int dx[4] = {1, 0, -1, 0};
// int dy[4] = {0, 1, 0, -1};
// bool is_in_range(int x, int y)
// {
//     return x >= 0 && y >= 0 && x < N && y < N;
// }

// bool delete_size_by(int canv_size, int src_x, int src_y, vector<pair<int, int>> &canvas)
// {
//     int result = 0;
//     vector<pair<int, int>> checker;
//     vector<int> checker_idx;
//     for (int i = 0; i < canv_size; i++)
//     {
//         for (int j = 0; j < canv_size; j++)
//         {
//             int px = src_x + i;
//             int py = src_y + j;
//             if (!is_in_range(px, py))
//                 return false;
//             else
//             {
//                 checker.push_back({px, py});
//             }
//         }
//     }
//     for (int i = 0; i < canvas.size(); i++)
//     {
//         for (int j = 0; j < checker.size(); j++)
//         {
//             if (canvas[i].first == checker[j].first && canvas[i].second == checker[j].second)
//             {
//                 checker_idx.push_back(i);
//                 result++;
//             }
//         }
//     }

//     if (result == canv_size * canv_size)
//     { // checked
//         for (auto iter = checker_idx.rbegin(); iter != checker_idx.rend(); iter++)
//         {
//             int px = canvas[(*iter)].first;
//             int py = canvas[(*iter)].second;
//             graph[px][py] = 0;
//             canvas.erase(canvas.begin() + (*iter));
//         }
//         return true;
//     }
//     else
//         return false;
// }

// int bfs(int init_x, int init_y)
// {
//     vector<pair<int, int>> canvas;
//     vector<vector<bool>> visited(N, vector<bool>(N, false));
//     queue<pair<int, int>> q;
//     int result = 0;
//     int walk = 6;
//     int left_paper = 0;
//     q.push({init_x, init_y});
//     visited[init_x][init_y] = true;
//     canvas.push_back({init_x, init_y});
//     while (!q.empty())
//     {
//         auto cur = q.front();
//         q.pop();
//         for (int i = 0; i < 4; i++)
//         {
//             int px = cur.first + dx[i];
//             int py = cur.second + dy[i];

//             if (is_in_range(px, py) && !visited[px][py] && graph[px][py] == 1)
//             {
//                 visited[px][py] = true;
//                 canvas.push_back({px, py});
//                 q.push({px, py});
//             }
//         }
//     }
//     while (walk--)
//     {

//         for (int i = canvas.size() - 1; i >= 0; i--)
//         {
//             if (delete_size_by(walk, canvas[i].first, canvas[i].second, canvas))
//             {

//                 color_paper[walk]--;
//                 result++;
//                 if (color_paper[walk] == 0)
//                 {
//                     walk--;
//                     break;
//                 }
//             }
//         }
//     }
//     for (auto e : color_paper)
//     {
//         left_paper+=e;
//     }
//     if (!canvas.empty()&&left_paper>0)
//         return -1;
//     return result;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     graph.resize(N, vector<int>(N, 0));
//     int answer = 0;
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < N; j++)
//         {
//             cin >> graph[i][j];
//         }
//     }
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < N; j++)
//         {
//             if (graph[i][j] == 1)
//             {
//                 int result = bfs(i, j);
//                 if (result == -1)
//                 {
//                     cout << -1;
//                     return 0;
//                 }
//                 else
//                     answer += result;
//             }
//         }
//     }
//     cout << answer;
//     return 0;
// }

// 2022-04-20 17:45:41 문제 보기 시작
// 2022-04-20 17:54:51 이어폰 놓고와서 걸어다니면서 문제 풀이법 생각해냄 (ㄹㅈㄷ)
// 맵 받고, 맵 순회하면서 BFS로 pair<int,int>로 걔네들 받음
// 함수 하나 만들어서 (bool size_check_by(int N)) 체크(큰거부터 해야함)
// 4x4 되는지 확인 (전체) -> 3x3 ...
// 가보자 !

// 2022-04-20 17:56:00 구현 시작

// 2022-04-20 19:27:15 색종이 남은 개수를 사용하는 방식에서 뭔가 크게 잘못됐다..
// 2022-04-20 19:35:56 그리디하게 풀면 (큰 종이부터 사용하면) 접근 불가능하다..
// 2022-04-21 00:35:44 포기...