class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        // Queue to store nodes along with their indices
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});  // root node has index 0
        unsigned long long maxWidth = 0;

        while (!q.empty()) {
            int size = q.size();
            unsigned long long minIndex = q.front().second;  // Minimum index at the current level
            unsigned long long first, last;

            for (int i = 0; i < size; ++i) {
                unsigned long long currIndex = q.front().second - minIndex;  // Normalize indices to avoid overflow
                TreeNode* node = q.front().first;
                q.pop();

                if (i == 0) first = currIndex;  // First node index at this level
                if (i == size - 1) last = currIndex;  // Last node index at this level

                if (node->left) q.push({node->left, 2 * currIndex + 1});
                if (node->right) q.push({node->right, 2 * currIndex + 2});
            }

            // Calculate the width for this level
            maxWidth = max(maxWidth, last - first + 1);
        }

        return maxWidth;
    }
};
