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
class BSTIterator {
public:
    queue<int> q;
    void getInorder(TreeNode* root){
        if(!root) return;
        getInorder(root->left);
        q.push(root->val);
        getInorder(root->right);
    }
    BSTIterator(TreeNode* root) {
        getInorder(root);
    }
    
    int next() {
        int ans = q.front();
        q.pop();
        return ans;
        
    }
    
    bool hasNext() {
        if(q.empty()) return false;
        else return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */