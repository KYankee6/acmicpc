// https://www.acmicpc.net/problem/5052
// 전화번호 목록
// 트라이 자료구조
// 2022-05-21 19:05:28
// 예외케이스 -> sort를 안하면 더 적은 수의 문자열의 뒤로 왔을 때 예외가 된다.
// 배부르다자자. 2022-05-21 23:46:25

#include <bits/stdc++.h>
using namespace std;
#define MAX_CHILD 10

bool answer = false;
struct Trie
{
    char x;
    Trie *children[MAX_CHILD]={};
    bool isEnd=false;
    Trie(){};
    Trie(char _x) : x(_x), isEnd(false){};
    ~Trie()
    {
        for (int i = 0; i < MAX_CHILD; i++)
        {
            if (children[i] != nullptr)
            {
                delete children[i];
            }
        }
    }

    void insert(string &str, int idx)
    {
        if (idx == str.size())
        {
            isEnd = true;
        }
        else
        {
            if (isEnd)
            {
                answer = true;
                return;
            }
            int child_idx = str[idx] - '0';
            if (children[child_idx] == nullptr)
            {
                children[child_idx] = new Trie;
            }
            children[child_idx]->insert(str, idx + 1);
        }
    }
};

main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        Trie *root = new Trie;
        answer = false;
        vector<string> numbers;
        for (int i = 0; i < n; i++)
        {
            string number;
            cin >> number;
            numbers.push_back(number);
        }
        sort(numbers.begin(),numbers.end());
        for(int i=0; i<n; i++){
            root->insert(numbers[i],0);
        }
        if (!answer)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
        delete root;
    }
}