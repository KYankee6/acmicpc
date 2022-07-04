/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    map<int,string> m;
    m[0] = "Not a pangram";
    m[1] = "Pangram!";
    m[2] = "Double pangram!!";
    m[3] = "Triple pangram!!!";
    int T;
    cin>>T;
    cin.ignore();
    for(int q=1; q<=T; q++){
        vector<int> v(256,0);
        string s;
        getline(cin,s);
        for(int i=0; i<s.size(); i++){
            v[(int)toupper(s[i])]++;
        }
        cout<<"Case "<<q<<": "<<m[*min_element(v.begin()+65, v.begin()+91)]<<"\n";
    }
    return 0;
}
