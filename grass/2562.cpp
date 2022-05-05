#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> v;
    int x;
    while(cin>>x){
        v.push_back(x);
    }
    cout<<*max_element(v.begin(),v.end())<<endl;
    cout<<max_element(v.begin(),v.end())-v.begin()+1;
}