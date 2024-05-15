#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* result;
    cout << lists.empty() << endl;
    while (!lists.empty()) {

    }
    return result;
}       

int main () {
    vector<ListNode*> testcase;

    testcase.push_back(new ListNode(1,
                       new ListNode(2,
                       new ListNode (3))));
    testcase.push_back(new ListNode(6,
                       new ListNode(7,
                       new ListNode (8))));
    testcase.push_back(new ListNode(3,
                       new ListNode(4,
                       new ListNode (9))));

    return 0;
}