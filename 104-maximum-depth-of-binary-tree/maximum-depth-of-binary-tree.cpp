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
// RECURSIVE SOLN
// height  = 1+ max (left sub tree height, right sub tree height);
int maxH(TreeNode* root){
    TreeNode* l,r;
    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    if(root->left==NULL) return 1+maxH(root->right);
    if(root->right==NULL) return 1+maxH(root->left);
    return 1+ max(maxH(root->left),maxH(root->right));

}
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        return maxH(root);
    }
};