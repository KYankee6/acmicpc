#include <bits/stdc++.h>

using namespace std;



int main()
{
    while (true)
    {
        vector<int> v;
        vector<bool> temp;
        string s = "";
        getline(cin, s);
        stringstream ss(s);
        string val;
        while(getline(ss,val,' ')){
            if(val.compare("0")==0)return 0;
            v.push_back(stoi(val));
        }
        v.erase(v.begin());
        sort(v.begin(), v.end());
        temp.resize(v.size(), false);
        for (int i = 0; i < 6; i++)
        {
            temp[i] = true;
        }
        do
        {
            for(int i=0; i<temp.size(); i++){
                if(temp[i])cout<<v[i]<<" ";
            }
            cout<<"\n";
        } while (prev_permutation(temp.begin(), temp.end()));
        cout<<"\n";
    }
}