// https://www.acmicpc.net/problem/5052
// 전화번호 목록
// 트라이 자료구조
// 2022-05-21 19:05:28

#include <bits/stdc++.h>
using namespace std;
#define MAX_CHILD 10

struct Trie
{
    char x;
    Trie *children[MAX_CHILD];
    bool isEnd;
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

    bool insert(string &str, int idx)
    {
        if (idx == str.size())
        {
            isEnd = true;
        }
        else
        {
            char cur = str[idx];
            if (find(cur) == false)
            {
                int next = cur - '0';
                children[next] = new Trie(cur);
                if (!insert(str, idx + 1))
                    return false;
            }
            else
            {
                if (isEnd)
                    return false;
                if (!insert(str, idx + 1))
                    return false;
            }
        }
        return true;
    }

    bool find(char cur)
    {
        int idx = cur - '0';
        return children[idx] == nullptr;
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
        Trie *root = new Trie('.');
        bool result = true;
        for (int i = 0; i < n; i++)
        {
            string number;
            cin >> number;
            if (!root->insert(number, 0))
            {
                result = false;
                break;
            }
        }
        if (result)
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