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
void inorder1(TreeNode* root,int& c,int& s)
{
    if(root==NULL) return;
    inorder1(root->left,c,s);
    s+=root->val;
    c++;
    inorder1(root->right,c,s);
}
void inorder2(TreeNode* root,int &k)
{
    if(root==NULL) return;
    inorder2(root->left,k);
    int s=0,c=0;
    inorder1(root,c,s);
    if (c > 0 && s / c == root->val) k++;
    inorder2(root->right,k);
}
    int averageOfSubtree(TreeNode* root) {
        int k=0;
        inorder2(root,k);
        return k;
    }
};