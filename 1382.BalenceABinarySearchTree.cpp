//Difficulty: Med.
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

void inorder(TreeNode* root, vector<TreeNode*> &nodes) {
    if (root == NULL) return;
    inorder(root->left, nodes);
    nodes.push_back(root);
    inorder(root->right, nodes);
}

TreeNode* solve(vector<TreeNode*> &nodes, int start, int end) {
    if (end < start) return NULL;
    int mid = (end - start) / 2 + start;
    TreeNode* root = nodes[mid];
    root->left = solve(nodes, start, mid-1);
    root->right = solve(nodes, mid+1, end);
    return root;
}

TreeNode* balanceBST(TreeNode* root) {
    if(root == NULL) return NULL;
    vector<TreeNode*> inorder_traversal;
    inorder(root, inorder_traversal);
    return solve(inorder_traversal, 0, inorder_traversal.size()-1);
}

void printNodes(TreeNode* node) {
    if (node == NULL) {
        cout << "null ";
        return;
    }
    cout << node->val << " ";
    printNodes(node->left);
    printNodes(node->right);
}

int main () {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);
    root = balanceBST(root);
    printNodes(root);
    return 0;
}