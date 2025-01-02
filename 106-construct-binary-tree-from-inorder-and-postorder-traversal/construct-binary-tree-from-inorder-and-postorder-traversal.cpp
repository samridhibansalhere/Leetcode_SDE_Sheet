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
TreeNode* build(vector<int>& postorder,int poststart,int postend, vector<int>& inorder,int instart,int inend,map<int,int>&mp){
    if(poststart>postend || instart>inend) return NULL;
    TreeNode* root=new TreeNode(postorder[postend]);
    int inRoot=mp[root->val];
    int num=inRoot-instart;
    root->left=build(postorder,poststart,poststart+num-1,inorder,instart,inRoot-1,mp);
    root->right=build(postorder,poststart+num,postend-1,inorder,inRoot+1,inend,mp);
    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()) return NULL;
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return build(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mp);
    }
};