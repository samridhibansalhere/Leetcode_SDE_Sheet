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
class FindElements {
public:
    TreeNode* node;
    
    void correct(TreeNode* root, int parent, int c) {
        if (root == nullptr) return;
        correct(root->left, 2 * parent + 1, 1);
        root->val =parent;;
        correct(root->right, 2 * parent + 2, 2);
        node = root;
    }
    
    bool loc(TreeNode* node, int target) {
        if (node == nullptr) return false;
        if (node->val == target) return true;
        if (loc(node->left, target)) return true;
        return loc(node->right, target);
    }
    
    FindElements(TreeNode* root) {
        correct(root, 0, 0);
    }
    
    bool find(int target) {
        return loc(node, target);
    }
};
