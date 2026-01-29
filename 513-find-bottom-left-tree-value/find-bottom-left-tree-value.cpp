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
void helper(TreeNode* node,int level,vector<int>&ans)
{
    if(node==NULL) return;
    if(level==ans.size()) ans.push_back(node->val);
    if(node->left) helper(node->left,level+1,ans);
    if(node->right) helper(node->right,level+1,ans);
    
}
    int findBottomLeftValue(TreeNode* root) {
       vector<int> ans;
        helper(root,0,ans);
        return ans[ans.size()-1];
    }
};