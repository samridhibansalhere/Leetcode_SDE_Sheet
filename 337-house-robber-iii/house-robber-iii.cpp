class Solution {
public:
    // Helper function that returns two values:
    // first value is the max money we can rob from the current subtree if we rob the current node
    // second value is the max money we can rob from the current subtree if we do not rob the current node
    pair<int, int> call(TreeNode* root) {
        if (!root) return {0, 0}; 
        auto left = call(root->left);   
        auto right = call(root->right); 
        int robCurrent = root->val + left.second + right.second;
        
        int skipCurrent = max(left.first, left.second) + max(right.first, right.second);
        
        return {robCurrent, skipCurrent};
    }

    int rob(TreeNode* root) {
        auto result = call(root);  
        return max(result.first, result.second); 
    }
};
