class Solution {
public:
    // Helper function that returns two values:
    // first value is the max money we can rob from the current subtree if we rob the current node
    // second value is the max money we can rob from the current subtree if we do not rob the current node
    pair<int, int> call(TreeNode* root) {
        if (!root) return {0, 0};  // Base case: no node means no money
        
        auto left = call(root->left);   // Left child results
        auto right = call(root->right); // Right child results
        
        // If we rob the current node, we can't rob its children
        int robCurrent = root->val + left.second + right.second;
        
        // If we skip the current node, we can rob its children
        int skipCurrent = max(left.first, left.second) + max(right.first, right.second);
        
        return {robCurrent, skipCurrent};
    }

    int rob(TreeNode* root) {
        auto result = call(root);  // Get the results from the call function
        return max(result.first, result.second);  // Max of robbing or not robbing the root node
    }
};
