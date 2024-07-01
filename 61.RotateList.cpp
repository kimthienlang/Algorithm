#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* rotateRight(ListNode *head, int k) {
    if(head == NULL || head->next == NULL||k==0) return head;

    ListNode* node = head;
    int size =1;

    while(node->next != NULL)
    {
        size++;
        node = node->next;
    }

    node->next=head;

    k = k%size;

    while(--size >= k)
    {
        node=node->next;
    }

    ListNode* first = node->next;
    node->next=NULL;

    return first;
}

int main() {
    ListNode* head;
    int k = 3;
    head->val = 1;
    head->next->val = 2;
    head->next->next->val = 3;
    head->next->next->next->val = 4;
    head->next->next->next->next->val = 5;
    ListNode* res = rotateRight(head, k);
    return 0;
}