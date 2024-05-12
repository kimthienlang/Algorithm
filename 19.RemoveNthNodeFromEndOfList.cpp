#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* result = new ListNode(0, head);
        ListNode* dummy = result;

        for (int i = 0; i < n; i++) {
            head = head->next;
            cout << "i: " << head->val << endl;
        }

        while (head != nullptr) {
            dummy = dummy->next;
            head = head->next;
        }

        dummy->next = dummy->next->next;
        return result->next;        
    }
};
int main() {
    ListNode *head = new ListNode(1, 
                     new ListNode(2, 
                     new ListNode(3, 
                     new ListNode(4, 
                     new ListNode(5)))));
    int n = 2;
    Solution sol;
    ListNode *result;
    result = sol.removeNthFromEnd(head, n);
    while(result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}