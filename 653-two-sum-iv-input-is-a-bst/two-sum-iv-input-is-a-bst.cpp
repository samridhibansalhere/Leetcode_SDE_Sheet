#include <stack>

class BSTIterator {
private:
    std::stack<TreeNode*> stk;
    bool reverse; 

    void pushAll(TreeNode* node) {
        while (node != nullptr) {
            stk.push(node);
            node = reverse ? node->right : node->left;
        }
    }

public:
    BSTIterator(TreeNode* root, bool isReverse) : reverse(isReverse) {
        pushAll(root);
    }

    int next() {
        TreeNode* node = stk.top();
        stk.pop();
        if (!reverse) {
            pushAll(node->right);
        } else {
            pushAll(node->left);
        }
        return node->val;
    }

    bool hasNext() {
        return !stk.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        int i=l.next();
        int j=r.next();
        while(i<j)
        {
            if(i+j==k) return true;
            if(i+j<k) i=l.next();
            else j=r.next();
        }
        return false;
    }
};