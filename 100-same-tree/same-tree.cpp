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
bool flag  = true;
void compareT(TreeNode* p, TreeNode* q){
    if(p==NULL || q==NULL){
        if(!(p==NULL && q==NULL)) flag = false;
        return;
    }
    if(p->val!=q->val){
        flag = false;
        return;
    }
    compareT(p->left,q->left);
    compareT(p->right,q->right);
    return;
}
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        compareT(p,q);
        return flag;
    }
};