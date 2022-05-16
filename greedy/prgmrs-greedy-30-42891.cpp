// https://programmers.co.kr/learn/courses/30/lessons/42891
// 2022-05-16 23:02:53 무지의 먹방 라이브 (4트)

// 여러가지 생각들이 많이 드는 문제다..
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    priority_queue<pair<int,int>> pq;
    long long ft_cnt = (long long)food_times.size();
    long long sum = 0L;
    long long ft_time = 0L;
    int prev = 0;
    int now = 0;
    int left = 0;
    for(int i=0; i<food_times.size(); i++){
        pq.push({-food_times[i], i+1});
        sum+=food_times[i];
    }
    
    // if((long long)(*max_element(food_times.begin(),food_times.end()))*(long long)ft_cnt<=k) return -1;
    // 이게 안되는 이유가 도대체 무엇이오,,

    if(sum<=k)return -1;
    while(ft_time + (-pq.top().first-prev)*ft_cnt <= k){
        now = -pq.top().first;
        pq.pop();
        ft_time += (now-prev)*ft_cnt;
        ft_cnt--;
        prev = now;
    }
    vector<pair<int,int>> v;
    while(!pq.empty()){
        int first = -pq.top().first;
        int second = pq.top().second;
        v.push_back({second,first});
        pq.pop();
    }
    sort(v.begin(),v.end());
    k-=ft_time;
    k = k%v.size();
    answer = v[k].first;
    return answer;
}