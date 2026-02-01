/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> mp;
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left){mp[curr->left]=curr; q.push(curr->left);}
            if(curr->right){mp[curr->right]=curr; q.push(curr->right);}
        }
        int level=0;
        vector<int> ans;
        q.push(target);
        visited[target]=true;
        while(!q.empty())
        {
            int size=q.size();
            if(level++==k) break;
            for(int i=0;i<size;i++){
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left && !visited[curr->left]) {q.push(curr->left); visited[curr->left]=true;} 
            if(curr->right && !visited[curr->right]) {q.push(curr->right); visited[curr->right]=true;} 
            if(mp[curr] && !visited[mp[curr]]) {q.push(mp[curr]); visited[mp[curr]]=true;} 
            }
        }
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};