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
class BSTIterator {
stack<TreeNode*> st;
bool reverse=true;
public:
BSTIterator(TreeNode* root,bool rev) {
       reverse=rev;
       pushval(root); 
    }
void pushval(TreeNode* root){
        while(root!=NULL)
        {
            st.push(root);
            if(!reverse)root=root->left;
            else root=root->right;
        }
    }
    
    int next() {
        TreeNode* temp=st.top();
        st.pop();
        if(!reverse)pushval(temp->right);
        else pushval(temp->left);
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
    bool findTarget(TreeNode* root, int k) {
        if(root==nullptr) return false;
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        int i=l.next();
        int j=r.next();
        while(i<j)
        {
            if(i+j==k) return true;
            if(i+j>k) j=r.next();
            else i=l.next();
        }
        return false;
}
    
};