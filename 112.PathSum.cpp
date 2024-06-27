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
    if(root == nullptr) return false;
    if(root->left == nullptr && root->right == nullptr && targetSum == root->val) return true;
    bool l = hasPathSum(root->left,  targetSum - root->val);
    bool r = hasPathSum(root->right, targetSum - root->val);
    return l | r;
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

    int target = 4;
    bool res = hasPathSum(root, target);
    cout << "OUTPUT: " << res << endl;

    return 0;
}