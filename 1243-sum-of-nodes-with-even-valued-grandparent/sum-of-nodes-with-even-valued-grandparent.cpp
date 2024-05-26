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
    void check(TreeNode* root, int level, int& s) {
        if (root == nullptr) return;
        if (level == 2) {
            s += root->val;
            return;
        }
        check(root->left, level + 1, s);
        check(root->right, level + 1, s);
    }

    void inorder(TreeNode* root, int& s) {
        if (root == nullptr) return;
        inorder(root->left, s);
        if (root->val % 2 == 0) {
            check(root->left, 1, s); 
            check(root->right, 1, s);
        }
        inorder(root->right, s);
    }

    int sumEvenGrandparent(TreeNode* root) {
        int s = 0;
        inorder(root, s);
        return s;
    }
};
