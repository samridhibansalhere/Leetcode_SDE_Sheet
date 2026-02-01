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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> mp;
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* target=nullptr;
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            if(curr->val==start) target=curr;
            if(curr->left){mp[curr->left]=curr; q.push(curr->left);}
            if(curr->right){mp[curr->right]=curr; q.push(curr->right);}
        }   
        int level=-1;
        q.push(target);
        visited[target]=true;
        while(!q.empty())
        {
            int size=q.size();
            level++;
            for(int i=0;i<size;i++){
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left && !visited[curr->left]) {q.push(curr->left); visited[curr->left]=true;} 
            if(curr->right && !visited[curr->right]) {q.push(curr->right); visited[curr->right]=true;} 
            if(mp[curr] && !visited[mp[curr]]) {q.push(mp[curr]); visited[mp[curr]]=true;} 
            }
        }
        return level;
    }
};