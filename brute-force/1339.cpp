// #include <bits/stdc++.h>

// using namespace std;

// vector<int> v;

// int alphabet_to_int(string str)
// {
//     int result =0;
//     for(int i=str.size()-1; i>=0; i--){
//         int idx = str[i]-'A';
//         result+=v[idx] * pow(10,i) ;
//     }
//     return result;

// }

// int main()
// {
//     int answer=-1;
//     int max_idx=-1;
//     int N;
//     cin>>N;
//     vector<string> strs;
//     for (int i = 9; i >= 0; i--)
//     {
//         v.push_back(i);
//     }
//     for (int i = 0; i < N; i++)
//     {
//         string s;
//         cin >> s;
//         strs.push_back(s);
//     }
//     do{
//         int result=0;
//         for(int i=0; i<N; i++){
//             result+=alphabet_to_int(strs[i]);
//         }
//         answer = max(answer,result);
//     }while(prev_permutation(v.begin(),v.end()));
//     cout<<answer;
// }

#include <bits/stdc++.h>

using namespace std;

// int alphabet_to_int(string str)
// {
// }

// bool sizecmp(string s1, string s2)
// {
//     return s1.size() > s2.size();
// }

int main()
{
    int answer = 0;
    int N;
    cin >> N;
    int number_of_alphabet=0;
    vector<string> strs;
    vector<long long> summation(26, 0);
    vector<int> v(26, 0);
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        strs.push_back(s);
        int str_size = s.size()-1;
        for (int j = 0; j < s.size(); j++)
        {
            int idx = strs[i][j] - 'A';
            int val = pow(10, str_size--);
            if(summation[idx]==0) number_of_alphabet++;
            summation[idx] += val;
        }
    }
    int walk = 9;
    for (int i = 0; i < number_of_alphabet; i++)
    {
        int max_idx = -1;
        int max_val = -1;
        for (int j = 0; j < 26; j++)
        {
            if (max_val < summation[j] && v[j] == 0)
            {
                max_val = summation[j];
                max_idx = j;
            }
        }
        v[max_idx] = walk--;
    }

    for (int i = 0; i < 26; i++)
    {
        answer += v[i] * summation[i];
    }
    cout << answer;
}