/*2058. Find the Minimum and Maximum Number of Nodes Between Critical Points*/
// Difficulty: Med.

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

const int _ = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}();

vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    vector<int> criticalPoints;
    ListNode* prev = nullptr;
    ListNode* curr = head;
    int position = 0;
    
    while (curr != nullptr && curr->next != nullptr) {
        if (prev != nullptr && curr->next != nullptr) {
            if ((curr->val > prev->val && curr->val > curr->next->val) || 
                (curr->val < prev->val && curr->val < curr->next->val)) {
                criticalPoints.push_back(position);
            }
        }
        prev = curr;
        curr = curr->next;
        position++;
    }
    
    if (criticalPoints.size() < 2) {
        return {-1, -1};
    }
    
    int minDistance = INT_MAX;
    int maxDistance = criticalPoints.back() - criticalPoints.front();
    
    for (int i = 1; i < criticalPoints.size(); i++) {
        minDistance = min(minDistance, criticalPoints[i] - criticalPoints[i - 1]);
    }
    
    return {minDistance, maxDistance};
}

int main () {
    ListNode* head = new ListNode(5,
                     new ListNode(3,
                     new ListNode(1,
                     new ListNode(2,
                     new ListNode(5,
                     new ListNode(1,
                     new ListNode(2)))))));
    vector<int> res = nodesBetweenCriticalPoints(head);
    for (auto x : res) cout << x << endl;
    return 0;
}

