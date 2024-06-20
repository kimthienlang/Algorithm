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

int minDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    int res = 1;
    int c1 = 1; 
    int c2 = 1;
    c1 += minDepth(root->left);
    c2 += minDepth(root->right);
    if (c1 != 1 && c2 != 1) res = min(c1, c2);
    else
    if (c1 == 1 && c2 != 1) res = c2;
    else 
    if (c1 != 1 && c2 == 1) res = c1;

    return res;    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    TreeNode* root = new TreeNode(2,
        nullptr,
        new TreeNode(3,
            nullptr,
            new TreeNode(4,
                nullptr,
                new TreeNode(5,
                    nullptr,
                    new TreeNode(6))))
    );
    int res = minDepth(root);
    cout << "RES: " << res << endl;
    return 0;
}
