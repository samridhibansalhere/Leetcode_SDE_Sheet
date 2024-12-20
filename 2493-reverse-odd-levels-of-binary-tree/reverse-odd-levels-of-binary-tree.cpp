class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return nullptr;

        // Queue for level order traversal
        std::queue<TreeNode*> q;
        q.push(root);
        bool isOddLevel = false; // Root level is level 0 (even)

        while (!q.empty()) {
            int levelSize = q.size();
            std::vector<TreeNode*> levelNodes;

            // Process the current level
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                // Collect nodes at the current level
                if (isOddLevel) {
                    levelNodes.push_back(node);
                }

                // Add children to the queue
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Reverse values for odd levels
            if (isOddLevel) {
                int n = levelNodes.size();
                for (int i = 0; i < n / 2; ++i) {
                    std::swap(levelNodes[i]->val, levelNodes[n - i - 1]->val);
                }
            }

            // Toggle level flag
            isOddLevel = !isOddLevel;
        }

        return root;
    }
};
