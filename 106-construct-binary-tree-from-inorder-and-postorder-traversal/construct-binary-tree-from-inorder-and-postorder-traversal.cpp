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
   TreeNode* build(vector<int>&post,int p,int q,vector<int>&in,int x,int y,unordered_map<int,int>&mp){
    if(p>q || x>y) return nullptr;
    int val=post[q];
    TreeNode* root=new TreeNode(val);
    int index=mp[val];
    int values=index-x;
    root->left=build(post,p,p+values-1,in,x,index-1,mp);
    root->right=build(post,p+values,q-1,in,index+1,y,mp);
    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int,int> mp;
    for(int i=0;i<inorder.size();i++) mp[inorder[i]]=i;
    return build(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mp)   ; 
    }
};