#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* root = new ListNode();    
    ListNode* dummyRoot = root;    
    ListNode* dummyHead = head;
    while (dummyHead != nullptr && dummyHead->next != nullptr) {
        dummyRoot->next = new ListNode();
        dummyRoot = dummyRoot->next;

        dummyRoot->val = dummyHead->next->val;
        dummyRoot->next = new ListNode(dummyHead->val);

        dummyHead = dummyHead->next->next;
        dummyRoot = dummyRoot->next;
    }
    if (dummyHead != nullptr) {
        dummyRoot->next = new ListNode(dummyHead->val);
    }
    return root->next;   
}

int main() {
    ListNode* testcase = new ListNode(1,
                         new ListNode(2,
                         new ListNode(3,
                         new ListNode(4,
                         new ListNode(5)))));
    
    ListNode* result = swapPairs(testcase);
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}