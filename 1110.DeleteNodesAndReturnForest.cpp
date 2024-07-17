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


void dfs(TreeNode* &root, bool flag, vector<TreeNode*>& res, bool set[]){
    if (root == nullptr) return;
    dfs(root->left, set[root->val], res, set);
    dfs(root->right, set[root->val], res, set);
    if (!set[root->val] && flag) res.push_back(root);
    if (set[root->val]) root = nullptr;
}

vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    vector<TreeNode*> res;
    bool set[1001];

    for (int num : to_delete)
        set[num] = true;
    dfs(root, true, res, set);
    return res;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    vector<int> to_delete = {3, 5};
    vector<TreeNode*> res = delNodes(root, to_delete);
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); ++i)
        cout << res[i]->val << endl;
    return 0;
}