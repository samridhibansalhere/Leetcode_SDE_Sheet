/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        if(root==nullptr) return "";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            if(node==nullptr) s+="#,";
            else{
                s+=to_string(node->val)+",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        cout<<s;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        if(s.size()==0) return nullptr;
        stringstream s2(s);
        string str;
        getline(s2,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            getline(s2,str,',');
            if(str=="#") node->left=nullptr;
            else {
                TreeNode* left=new TreeNode(stoi(str));
                node->left=left;
                q.push(node->left);
            }
            getline(s2,str,',');
            if(str=="#") node->right=nullptr;
            else {
                TreeNode* right=new TreeNode(stoi(str));
                node->right=right;
                q.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));