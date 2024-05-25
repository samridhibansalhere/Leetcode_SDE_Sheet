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
class BSTIterator {
public:
vector<int> a;
int index=0;
    void inorder(TreeNode* root, vector<int>& a) {
        if (root == nullptr) return;
        inorder(root->left, a);
        a.push_back(root->val);
        inorder(root->right, a); 
    }
    BSTIterator(TreeNode* root) {
        inorder(root,a);
    }
    
    int next() {
        return a[index++];
    }
    
    bool hasNext() {
        return index<a.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */