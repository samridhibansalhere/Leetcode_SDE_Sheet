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
int findleft(TreeNode* node){
    int c=0;
    while(node)
    {
        c++;
        node=node->left;
    }
    return c;
}
int findright(TreeNode* node){
    int c=0;
    while(node)
    {
        c++;
        node=node->right;
    }
    return c;
}
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int left=findleft(root);
        int right=findright(root);
        if(left==right) return (1<<left)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};