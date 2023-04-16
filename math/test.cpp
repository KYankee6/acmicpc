#include <bits/stdc++.h>

using namespace std;
int lengthOfLongestSubstring(string s) {
        map<char, int> st;
        int output = 1;
        int l = 0;
        if(s.empty()) return 0;
        st[s[l]] = l; //index
        for(int r = 0; r<s.length(); r++){
            if(st.find(s[r])!=st.end()){ // 찾은 경우
                if(l==r){
                    continue;
                }
                else{
                    int temp = st[s[r]]+1;
                    for(int i=l; i<=st[s[r]]; i++){
                        st.erase(s[i]);
                    }
                    l = temp;
                }
            }
            else{
                output = max(output, r-l+1);
                st[s[r]] = r;
            }
        }
        return output;
    }

int main(){
    string s = "bbtablud";
    cout<<lengthOfLongestSubstring(s);

}