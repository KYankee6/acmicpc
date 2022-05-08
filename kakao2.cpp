// #include <bits/stdc++.h>
// using namespace std;
// typedef unsigned long long ull;
// #define N queue1.size()
// int solution(vector<int> queue1, vector<int> queue2)
// {
//     int answer = -2;
//     priority_queue<int> pq;
//     int start = 0;
//     int end = 0;
//     ull cur_sum = 0ULL;
//     ull s1= accumulate(queue1.begin(), queue1.end(), 0ULL);
//     ull s2 =accumulate(queue2.begin(), queue2.end(), 0ULL);
//     ull total_sum = s1 + s2;
//     ull middle = total_sum / 2;
//     if(accumulate(queue1.begin(), queue1.end(), 0ULL)== middle || accumulate(queue2.begin(), queue2.end(), 0ULL)==middle ){
//         return 0;
//     }
//     vector<int> v;
//     v.reserve(queue1.size() + queue2.size());
//     v.insert(v.end(), queue1.begin(), queue1.end());
//     v.insert(v.end(), queue2.begin(), queue2.end());
//     while (start <v.size())
//     {
//         if(end==v.size() && cur_sum<middle) break;
//         if(cur_sum>=middle){
//             cur_sum-=v[start];
//             start++;
//         }
//         else if (cur_sum < middle && end < v.size())
//         {
//             cur_sum += v[end];
//             end++;
//         }
//         if (cur_sum == middle)
//         {
//             if (start < N && end < N)
//             {
//                 if (end == N - 1)
//                 {
//                     pq.push(-(start + 1));
//                 }
//                 else
//                     pq.push(-((start + 1) * 2 + N + end + 1));
//             }
//             if (start < N && end >= N)
//             {
//                 pq.push(-(start + (end - N)));
//             }
//             // if (start >= N && end <N)//impossible
//             if (start >= N && end >= N)
//             {
//                 if (end == 2 * N - 1 && N-start !=0)
//                 {
//                     pq.push(-(N - start));
//                 }
//                 pq.push(-(end + (start-N)));
//             }
//         }
//     }
//     if (pq.empty())
//         answer = -1;
//     else
//         answer = -pq.top();
//     return answer;
// }
// int main()
// {
//     vector<int> q1 = {1, 2, 1, 2};
//     vector<int> q2 = {1, 10, 1, 2};
//     cout << solution(q1, q2);
// }
