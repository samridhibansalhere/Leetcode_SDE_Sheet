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
    void inorder1(TreeNode* root, int c, vector<vector<int>>& a) {
        if (root == nullptr) return;
        if (c >= a.size()) a.resize(c + 1); 
        inorder1(root->left, c + 1, a);
        if (c % 2 == 0) {
            a[c].push_back(root->val);
        }
        inorder1(root->right, c + 1, a);
    }

    void inorder2(TreeNode* root, int c, vector<vector<int>>& a) {
        if (root == nullptr) return;
        inorder2(root->left, c + 1, a);
        if (c % 2 == 0 && !a[c].empty()) {
            root->val = a[c].back();
            a[c].pop_back();
        }
        inorder2(root->right, c + 1, a);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<vector<int>> a;
        inorder1(root, 1, a);
        for (int i = 1; i < a.size(); i += 2) {
            reverse(a[i].begin(), a[i].end());
        }
        inorder2(root, 1, a);
        return root;
    }
};
