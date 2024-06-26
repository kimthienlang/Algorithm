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


bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) return false;
    if (root->val == targetSum) {
        return true;
    } 
    if (root->left != nullptr) {
        root->left->val += root->val;
        hasPathSum(root->left, targetSum);
    }
    if (root->right != nullptr) {
        root->right->val += root->val;
        hasPathSum(root->right, targetSum);
    }
    return false;
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left  = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left   = new TreeNode(11);
    root->right->left  = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left    = new TreeNode(7);
    root->left->left->right   = new TreeNode(2);
    root->right->right->right = new TreeNode(1);

    int target = 22;
    bool res = hasPathSum(root, target);
    cout << "OUTPUT: " << res << endl;

    return 0;
}