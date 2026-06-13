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
//BRUTE FORCE
int getMin(TreeNode* root){
    while(root->left){
        root=root->left;
    }
    return root->val;
}
int getMax(TreeNode* root){
    while(root->right){
        root=root->right;
    }
    return root->val;
}
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        bool right = isValidBST(root->right);
        bool left= isValidBST(root->left);
        bool condn = true;
        if(root->right) condn = condn & (getMin(root->right)>root->val);
        if(root->left) condn = condn & (getMax(root->left)<root->val);

        return (left && right && condn);
    }
};