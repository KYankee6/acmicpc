#include <bits/stdc++.h>

using namespace std;

int main(){

    vector<bool> v(42,false);

    for(int i=0; i<10; i++){

        int n;

        cin>>n;

        v[n%42]=true;

        }
    cout<<accumulate(v.begin(),v.end(),0);
    return 0;
    }

    
