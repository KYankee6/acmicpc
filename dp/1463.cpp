#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    int answer=0;
    cin>> N;
    while(N!=1){
        if(N%3==0) N/=3;
        else if(N%2==0) N/=2;
        else N--;
        answer++;
    }
    cout<<answer;
}