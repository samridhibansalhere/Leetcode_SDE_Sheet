class Solution {
public:
    void inorder(TreeNode* root, vector<int>& a) {
        if (root == nullptr) return;
        inorder(root->left, a);
        a.push_back(root->val);
        inorder(root->right, a);
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans;
        vector<int> a;
        inorder(root, a);
        int m = a.size();

        for (int i = 0; i < queries.size(); i++) {
            int c = queries[i];
            int mini = -1;
            int maxi = -1;
            auto it = lower_bound(a.begin(), a.end(), c);

            if (it == a.begin()) mini = -1;
            else mini = *(it - 1);

            if (it == a.end()) maxi = -1;
            else if (*it == c) mini = maxi = *it; 
            else maxi = *it;

            ans.push_back({mini, maxi});
        }

        return ans;
    }
};
