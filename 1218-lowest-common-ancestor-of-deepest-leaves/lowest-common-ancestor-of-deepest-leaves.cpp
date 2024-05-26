class Solution {
public:
    int height(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = height(root->left);
        int right = height(root->right);
        return max(left, right) + 1;
    }

    void inorder(TreeNode* root, int c, int height, vector<TreeNode*>& a) {
        if (root == NULL) return;
        inorder(root->left, c + 1, height, a);
        if (root->left == NULL && root->right == NULL && c == height) {
            a.push_back(root);
        }
        inorder(root->right, c + 1, height, a);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        if (root->val == p->val || root->val == q->val) return root; 
        TreeNode* leftans = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightans = lowestCommonAncestor(root->right, p, q);
        if (leftans != NULL && rightans != NULL) return root;
        else if (leftans != NULL) return leftans;
        else if (rightans != NULL) return rightans;
        else return NULL;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int h = height(root) - 1;
        vector<TreeNode*> a;
        inorder(root, 0, h, a);
        
        while(a.size() > 1) {
            TreeNode* p = a.back();
            a.pop_back();
            TreeNode* q = a.back();
            a.pop_back();
            a.push_back(lowestCommonAncestor(root, p, q));
        }
        
        return a[0];
    }
};
