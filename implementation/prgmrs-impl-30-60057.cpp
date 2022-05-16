// https://programmers.co.kr/learn/courses/30/lessons/60057
// 문자열 압축하기

// 2022-05-16 23:46:41
// int temp = to_string(cnt+1).size();
// 어........................... ㅎㅎ!
// 2022-05-17 01:17:20 ac
#include <bits/stdc++.h>
using namespace std;

int solution(string s)
{
    int answer = s.size();
    for (int comp = 1; comp < (s.size()/2)+1; comp++)
    {
        int result = s.size();
        for (int i = 0; i < s.size() - comp;)
        {
            string zero = s.substr(i, comp);
            int cnt = 0;
            int comp_walk = i + comp;
            string cmpr = s.substr(comp_walk, comp);
            while (zero.compare(cmpr) == 0)
            {
                cnt++;
                comp_walk += comp;
                cmpr = s.substr(comp_walk, comp);
            }

            if (cnt == 0)
            {
                i += comp;
            }
            else
            {
                result -= (cnt + 1) * comp;
                int temp = to_string(cnt+1).size();
                result += comp + temp;
                i += (cnt+1) * comp;
            }
        }
        answer = min(result, answer);
    }
    return answer;
}
int main()
{
    cout << solution("aaaaaaaaaaaaaaabbbbbbbbbbc");
}