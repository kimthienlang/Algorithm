#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
    TreeNode* map[100001] = {};
    bool child[100001] = {};
    for (auto& d : descriptions){
        if (map[d[0]] == nullptr) map[d[0]] = new TreeNode(d[0]);
        TreeNode* node = (map[d[1]] == nullptr ? new TreeNode(d[1]) : map[d[1]]);
        if (d[2])
            map[d[0]]->left = node;
        else
            map[d[0]]->right = node;
        map[node->val] = node;
        child[d[1]] = true;
    }
    for (auto& d : descriptions)
        if (!child[d[0]])
            return map[d[0]];
    return nullptr;
}

int main() {
    vector<vector<int>> description = {
        {20, 15, 1},
        {20, 17, 0},
        {50, 20, 1},
        {50, 80, 0},
        {80, 19, 1}
    };

    TreeNode* res = createBinaryTree(description);
    return 0;
}