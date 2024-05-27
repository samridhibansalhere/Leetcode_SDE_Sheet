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
void inorder(TreeNode* root, int parent, vector<int>& ans)
{
    if (root == NULL) return; 
    if (root->left == NULL && root->right == NULL)
    { 
        ans.push_back(10 * parent + root->val);
        return;
    }
    inorder(root->left, 10 * parent + root->val, ans);
    inorder(root->right, 10 * parent + root->val, ans);
}


    int sumNumbers(TreeNode* root) {
        int parent=0;
        vector<int> ans;
        inorder(root,parent,ans);
        int s=0;
        for(auto i: ans)
        {
            s+=i;
        }
        return s;
    }
};