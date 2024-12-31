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
    int find(unordered_map<TreeNode*,TreeNode*> &parent,TreeNode* target){
        queue<TreeNode*> q;
        q.push(target);
        unordered_map<TreeNode*,bool> visited;
        visited[target]=true;
        int maxi=0;
        while(!q.empty()){
            int size=q.size();
            int current=0;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !visited[node->left]){
                    current=1;
                    q.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right && !visited[node->right]){
                    current=1;
                    q.push(node->right);
                    visited[node->right]=true;
                }
                if(parent[node] && !visited[parent[node]]){
                    current=1;
                    q.push(parent[node]);
                    visited[parent[node]]=true;
                }
            }
            if(current) maxi++;
        }
        return maxi;
}
    TreeNode* findparent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent,int start){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res;
        while(!q.empty()){
            TreeNode* node=q.front();
            if(node->val==start) res=node;
            q.pop();
            if(node->left){
                q.push(node->left);
                parent[node->left]=node;
            }
            if(node->right){
                q.push(node->right);
                parent[node->right]=node;
            }
        } 
        return res;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> parent;
        unordered_map<TreeNode*,bool> visited;
        TreeNode* target=findparent(root,parent,start);
        int maxi=find(parent,target);
        return maxi;    
    }
};