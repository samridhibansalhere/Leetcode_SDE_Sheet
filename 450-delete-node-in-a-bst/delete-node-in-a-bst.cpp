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
TreeNode* lastright(TreeNode* root)
{
    if(root->right==NULL) return root;
    else return lastright(root->right);
}
TreeNode* helper(TreeNode* root)
{
    if(root->left==nullptr) return root->right;
    if(root->right==nullptr) return root->left;
    lastright(root->left)->right=root->right;
    return root->left;
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return nullptr;
        if(root->val==key) return helper(root);
        TreeNode* dummy=root;
        while(root!=nullptr)
        {
            if(root->val<key && root->right!=NULL && root->right->val==key){ root->right=helper(root->right); break;}
            else if(root->val<key )root=root->right;
            if(root->val>key && root->left!=NULL && root->left->val==key) {root->left= helper(root->left); break;}
            else if(root->val>key )root=root->left;
        }
    return dummy;
    }
};