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
    static ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* result;
        return result;
    }
};

int main() {
    ListNode head = ListNode();
    int n = 2;
    Solution::removeNthFromEnd(&head, n);
    return 0;
}