#include <bits/stdc++.h>
using namespace std;

struct cmp{
    bool operator()(int p1, int p2) {
        if(abs(p1)!=abs(p2) ){
            return abs(p1)>abs(p2);
        }
        else if (abs(p1)==abs(p2)){
            return p1>p2;
        }
        else return abs(p1)>abs(p2);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    priority_queue<int,vector<int>,cmp> pq;
    int n;
    cin >>n;
    while(n--){
        int x;
        cin>> x;
        if(x != 0){
            pq.push(x);
        }
        else{
            if(pq.empty()){
                cout<<"0"<<endl;
            }
            else{
                cout<<pq.top()<<endl;
                pq.pop();
            }
        }

    }

    return 0;
}