#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *oddEvenList(ListNode *head)
{
    int arr[5001];
    int n = 0;
    int idx = 0;
    ListNode *pCur = head;
    ListNode *pPrev = head;
    ListNode *pNext = nullptr;
    while (true)
    {
        n++;
        if (n % 2 == 0)
            arr[idx++] = pCur->val;
        if (pCur->next == nullptr)
            break;
        pCur = pCur->next;
    }
    if (n <= 2)
        return head;
    pPrev = head->next;
    pCur = head->next;
    for (int i = 1; i < n; i++)
    {
        if (i % 2 == 0)
        {
            pPrev->val = pCur->val;
            pPrev = pPrev->next;
        }
        pCur = pCur->next;
    }
    pPrev = pPrev->next;
    idx = 0;
    while (true)
    {
        pPrev->val = arr[idx++];
        if (pPrev->next == nullptr)
            break;
        pPrev = pPrev->next;
    }
    return head;
}
int main(){
    
}