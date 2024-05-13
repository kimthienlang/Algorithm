#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* mergeList = new ListNode();
    ListNode* Dummy = mergeList;
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val < list2->val) {
            mergeList->next = new ListNode();
            mergeList = mergeList->next;
            mergeList->val = list1->val;
            list1 = list1->next;
        } else {
            mergeList->next = new ListNode();
            mergeList = mergeList->next;
            mergeList->val = list2->val;
            list2 = list2->next;
        }
    }
    while (list1 != nullptr) {
        mergeList->next = new ListNode();
        mergeList = mergeList->next;
        mergeList->val = list1->val;
        list1 = list1->next;
    }
    while (list2 != nullptr) {
        mergeList->next = new ListNode();
        mergeList = mergeList->next;
        mergeList->val = list2->val;
        list2 = list2->next;
    }
    return Dummy->next;
}

int main() {
    ListNode* list1 = new ListNode(1,
                      new ListNode(2,
                      new ListNode(3,
                      new ListNode(4))));

    ListNode* list2 = new ListNode(3,
                      new ListNode(4,
                      new ListNode(5,
                      new ListNode(9))));

    ListNode* mergedTowList = mergeTwoLists(list1, list2);

    while (mergedTowList != nullptr) {
        cout << mergedTowList->val << " ";
        mergedTowList = mergedTowList->next;
    }
    return 0;
}