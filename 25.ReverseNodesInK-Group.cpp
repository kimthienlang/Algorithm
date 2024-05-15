#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* result = head;
    vector<ListNode*> vectorNode;
    int countNode = 0;
    while (head != nullptr) {
        countNode++;
        ListNode* temp = head;
        vectorNode.push_back(temp);
        if (countNode == k) {
            int len = k / 2;
            for (int i = 0; i < len; ++i) {
                int tempVal = vectorNode[k - i - 1]->val;
                vectorNode[k - i - 1]->val = vectorNode[i]->val;
                vectorNode[i]->val = tempVal;
            }
            vector<ListNode*> x;
            vectorNode = x;
            countNode = 0;
        }
        head = head->next;
    }
    return result;  
}
int main () {
    int k = 4;
    ListNode* testcase = 
                        new ListNode(1,
                        new ListNode(2,
                        new ListNode(3,
                        new ListNode(4,
                        new ListNode(5)))));
            
    ListNode* result = reverseKGroup(testcase, k);
    while (result != nullptr) {
        cout << result->val << ",";
        cout << endl;
        result = result->next;
    }
    return 0;
}