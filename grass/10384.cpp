/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <cctype>
#include <map>
#include <cstring>
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
    for(int q=1; q<=T; q++){
        vector<int> v(256,0);
        string s;
        cin.getline(s);
        for(int i=0; i<s.size(); i++){
            v[(int)toupper(s[i])]++;
        }
        cout<<m[*max_element(v.begin()+65, v.begin()+91)];
    }
    return 0;
}
