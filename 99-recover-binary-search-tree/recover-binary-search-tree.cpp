/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder1(TreeNode* root, vector<int>& a) {
        if (root == nullptr) return;
        inorder1(root->left, a);
        a.push_back(root->val);
        inorder1(root->right, a); 
    }

    void inorder2(TreeNode* root, int x, int y, int m, int n, int& c) {
        if (root == nullptr) return;
        inorder2(root->left, x, y, m, n, c);
        if (root->val == x && c == m) root->val = y;
        else if (root->val == y && c == n) root->val = x;
        c++;
        inorder2(root->right, x, y, m, n, c); 
    }

    void recoverTree(TreeNode* root) {
        vector<int> a;
        inorder1(root, a);
        int x = 0, y = 0, m = 0, n = 0;
        for (int i = 1; i < a.size(); ++i) {
            if (a[i] < a[i - 1]) {
                y = a[i];
                if (x == 0) {
                    x = a[i - 1];
                    m = i - 1;
                    n = i;
                } else {
                    n = i;
                    break;
                }
            }
        }
        int c = 0;
        inorder2(root, x, y, m, n, c);
    }
};