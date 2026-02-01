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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            long long base=q.front().second;
            long long first,last;
            for(int i=0;i<size;i++)
            {
                auto[node,curr]=q.front();
                q.pop();
                curr=curr-base;
                if(i==0) first=curr;
                if(i==size-1) last=curr;
                if(node->left) q.push({node->left,2*curr+1});
                if(node->right) q.push({node->right,2*curr+2});
            }
            if(last-first+1>ans) ans=last-first+1;
        }
        return ans;
    }
};