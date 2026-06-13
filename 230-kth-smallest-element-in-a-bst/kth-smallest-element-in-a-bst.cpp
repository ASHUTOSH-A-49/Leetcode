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
class Solution {
public:
    void inord(TreeNode* root,int & k,vector<int> & el,int & ans,bool &flag){
        if(!root) return;
        if(flag) return;
        inord(root->left,k,el,ans,flag);
        el.push_back(root->val);
        if(el.size()==k){
            flag = true;
            ans = root->val;
        } 
        inord(root->right,k,el,ans,flag);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = root->val;
        bool flag = false;
        vector<int> el;
        inord(root,k,el,ans,flag);
        return ans;
    }
};