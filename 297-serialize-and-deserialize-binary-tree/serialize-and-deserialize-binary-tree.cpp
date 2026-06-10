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
        string res = "";
        if (root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (node == nullptr) {
                res += "#,"; // Added comma delimiter
            } else {
                res += to_string(node->val) + ","; // Added comma delimiter
                q.push(node->left);
                q.push(node->right);
            } 
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        stringstream ss(data);
        string item;
        getline(ss, item, ',');
        if (item == "#") return nullptr;
        TreeNode* root = new TreeNode(stoi(item)); 
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (getline(ss, item, ',')) {
                if (item != "#") {
                    curr->left = new TreeNode(stoi(item));
                    q.push(curr->left);
                }
            }
            if (getline(ss, item, ',')) {
                if (item != "#") {
                    curr->right = new TreeNode(stoi(item));
                    q.push(curr->right);
                }
            }
        }
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));