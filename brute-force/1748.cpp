// 2022-04-20 19:41:59 모르겠다 멘탍 ㅓ진다

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int temp = n;
    vector<int> store;
    long long answer = 0;
    int jarisoo = 1;
    while (temp)
    {
        int x = temp % 10;
        store.push_back(x);
        temp /= 10;
    }
    jarisoo = store.size();
    int walker = 1;
    for(int i=jarisoo-2; i>=0; i--){
        answer += (9*pow(10,walker-1))*walker;
        walker++;
    }
    answer += ((n-pow(10,jarisoo-1))+1)*jarisoo;
    cout<<answer;
    return 0;
}