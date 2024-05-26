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
void inorder(TreeNode* root,int& s)
{
    if(root==NULL) return ;
    inorder(root->right,s);
    s+=root->val;
    root->val=s;
    inorder(root->left,s);
}
    TreeNode* bstToGst(TreeNode* root) {
        int s=0;
        inorder(root,s);
        return root;
    }
};