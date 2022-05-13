// https://programmers.co.kr/learn/courses/30/lessons/42891
// REST한..건가.

// 2022-05-13 20:16:58
// 무지의 먹방 라이브

#include <bits/stdc++.h>

using namespace std;
// pair<int,int> min_el(vector<int>& ft){
//     int min_el = INT_MAX;
//     int idx = 0;
//     int cnt =0;
//     for(auto it = ft.begin(); it!=ft.end(); it++){
//         if(*it!=0)cnt++;
//         if(min_el>*it && *it !=0){
//             min_el = *it;
//             idx = it-ft.begin();
//         }
//     }
//     return {min_el*cnt,idx};
// }
// bool cmp(pair<int, int> p1, pair<int, int> p2)
// {
//     return p1.second < p2.second;
// }
// int solution(vector<int> food_times, long long k)
// {
//     int answer = 0;
//     long long walk = 0L;
//     vector<pair<int, int>> asc_food_times;
//     int cur_size = food_times.size();
//     for (int i = 0; i < food_times.size(); i++)
//     {
//         asc_food_times.push_back({i, food_times[i]});
//     }
//     sort(asc_food_times.begin(),asc_food_times.end(),cmp);
//     int height=0;
//     for (int i = 0; i < asc_food_times.size(); i++)
//     {
//         int result = asc_food_times[i].second * cur_size;
//         if (walk + result >= k)
//             break;
//         food_times[asc_food_times[i].first] = 0;
//         walk += result;
//         cur_size--;
//         height=asc_food_times[i].second;
//     }
//     for(int i=0; i<food_times.size(); i++){
//         food_times[i]-=height;
//     }
//     while (walk != k)
//     {
//         answer = answer % food_times.size();
//         if (food_times[answer] == 0)
//         {
//             answer++;
//             continue;
//         }
//         food_times[answer]--;
//         answer++;
//         walk++;
//     }
//     return answer;
// }
// int solution(vector<int> food_times, long long k) {
//     int answer = 0;
//     long long walk=0L;
//     while(true){
//         auto cur_iter = min_el(food_times);
//         if(cur_iter.first+walk >=k)break;
//         walk+=cur_iter.first;
//         answer = cur_iter.second;
//         food_times[cur_iter.second]=0;
//     }
//     while(walk!=k){
//         answer=answer%food_times.size();
//         if(food_times[answer]==0) {
//             answer++;
//             continue;
//         }
//         food_times[answer]--;
//         answer++;
//         walk++;
//     }
//     return answer;
// }

int main()
{
    vector<int> v = {3,1,2};
    auto it = min_element(v.begin(), v.end());
    cout << solution(v, 5L);
}