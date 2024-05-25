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
 void inorder(TreeNode* root, vector<int>& a) {
        if (root == nullptr) return;
        inorder(root->left, a);
        a.push_back(root->val);
        inorder(root->right, a); 
 }

    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root,ans);
        int i=0,j=ans.size()-1;
        while(i<j)
        {
            if(k==ans[i]+ans[j]) return true;
            else if(ans[i]+ans[j]>k) j--;
            else i++;
        }
        return false;
    }
};