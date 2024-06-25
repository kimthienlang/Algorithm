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


void rinorder(TreeNode* root, int &sum)
{
    if(root == nullptr) return;

    rinorder(root->right, sum);
    sum += root->val;
    root->val = sum;
    rinorder(root->left, sum);
}

TreeNode* bstToGst(TreeNode* root) {
    int sum = 0;
    rinorder(root, sum);
    return root;
}

void printNodes(TreeNode* root) {
    if (root == nullptr) {
        cout << "null "; 
        return;
    }
    cout << root->val << " ";
    printNodes(root->left);
    printNodes(root->right);
}

int main() {
    TreeNode* root = new TreeNode(4); // Khởi tạo nút gốc với giá trị 4
    root->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    root->left->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(8);
    TreeNode* res = bstToGst(root);
    printNodes(res);
    return 0;
}