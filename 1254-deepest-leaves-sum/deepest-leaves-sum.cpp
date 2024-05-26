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
    int calc(TreeNode* root) {
        if (root == NULL) return 0;
        int left = calc(root->left);
        int right = calc(root->right);
        return 1 + max(left,right);
    }

    void inorder(TreeNode* root, int c, int height, int& sum) {
        if (root == NULL) return;
        if (c==height) {
            sum += root->val;
        } else {
            inorder(root->left, c + 1, height, sum);
            inorder(root->right, c + 1, height, sum);
        }
    }

    int deepestLeavesSum(TreeNode* root) {
        int height = calc(root);
        int sum = 0;
        inorder(root, 0, height - 1, sum);
        return sum;
    }
};
