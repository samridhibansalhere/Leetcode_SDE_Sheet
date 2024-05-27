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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            vector<int> level;
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
    int maxLevelSum(TreeNode* root) {
        vector<vector<int>> ans=levelOrder(root);
        vector<int> level;
        for(int i=0;i<ans.size();i++)
        {
            int s=0;
            for(int j=0;j<ans[i].size();j++)
            {
                s+=ans[i][j];
            }
            level.push_back(s);
        }
        int c=level[0];
        for(auto i:level)
        {
            if(i>c) c=i;
        }
        for(int i=0;i<level.size();i++)
        {
            if(level[i]==c) return i+1;
        }
        return 0;
    }
};