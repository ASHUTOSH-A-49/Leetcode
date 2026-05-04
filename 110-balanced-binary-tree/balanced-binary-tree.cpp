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
//balanced BT : max height <= ceil(log2(n));
// int N = 0;
bool flag = true;
int maxH(TreeNode* root){
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    if(root->left==NULL){
        int r = maxH(root->right);
        if(r>1) flag = false;
        return 1+r;
    } 
    if(root->right==NULL){
        int l = maxH(root->left);
        if(l>1) flag = false;
        return 1+l;
    } 
    int l = maxH(root->left);
    int r = maxH(root->right);
    if(abs(l-r) > 1) flag = false;
    return 1+ max(l,r);
}
    bool isBalanced(TreeNode* root) {
        // int h = maxH(root);
        // if(N<=2) return true;
        // cout<<h<<" "<<N<<" "<<ceil(log2(N))<<endl;
        // if(h<=ceil(log2(N))) return true;
        // return false;
        int h = maxH(root);
        cout<<h<<endl;
        return flag;

    }
};