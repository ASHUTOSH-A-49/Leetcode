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
//BETTER - inorder recursive soln without extra vector space
void inorderTrav(TreeNode* root,TreeNode* &prev,TreeNode* &first,TreeNode* &mid,TreeNode* &last){
    if(!root) return;
    inorderTrav(root->left,prev,first,mid,last);
    if(prev){
        if(root->val < prev->val){
            if(!first && !mid){
                first = prev;
                mid = root;
            }else{
                last = root;
            }
        }
    }
    prev = root;
    inorderTrav(root->right,prev,first,mid,last);
}
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr,*mid = nullptr,*last = nullptr,*prev = nullptr;
        inorderTrav(root,prev,first,mid,last);
        if(last){
            int temp = last->val;
            last->val = first->val;
            first->val = temp;
        }else{
            int temp = mid->val;
            mid->val = first->val;
            first->val = temp;
        }

    }
};