#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeNodes(ListNode* head) {
    ListNode* modify = head->next; 
    ListNode* nextSum = modify;

    while (nextSum != nullptr) {
        int sum = 0;
        while (nextSum->val != 0) {
            sum += nextSum->val;
            nextSum = nextSum->next;
        }

        modify->val = sum;
        nextSum = nextSum->next;
        modify->next = nextSum;
        modify = modify->next;
    }
    return head->next; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ListNode* head = new ListNode(0,
                     new ListNode(3,
                     new ListNode(1,
                     new ListNode(0,
                     new ListNode(4,
                     new ListNode(5,
                     new ListNode(2,
                     new ListNode(0))))))));

    ListNode* res = mergeNodes(head);
    while(res!=nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    
    return 0;
}