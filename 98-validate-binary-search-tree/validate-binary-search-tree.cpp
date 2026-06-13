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
 typedef long long ll;
class Solution {
    
//RANGE BASED APPROACH
public:
bool checkBST(TreeNode* root,ll minr,ll maxr){
    bool left = true,right = true;
    if(root->right) right = checkBST(root->right,root->val,maxr);
    if(root->left) left  = checkBST(root->left,minr,root->val);
    if(root->val > minr && root->val <maxr && left && right) return true;
    return false;
}
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        ll minr = (ll)INT_MIN -1 ,maxr = (ll)INT_MAX+1;
        return checkBST(root,minr,maxr);
        
    }
};