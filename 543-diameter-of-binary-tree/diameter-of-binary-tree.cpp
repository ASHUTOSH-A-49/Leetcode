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
// diameter = check for every node as a root and get dia for every node and then get max dia

// O(N2) soln 
int ans = 0;
int depth(TreeNode* Node){
    if(Node->left==NULL && Node->right==NULL){
        return 1;
    }
    if(Node->left==NULL){
        return 1+depth(Node->right);
    }
    if(Node->right==NULL){
        return 1+depth(Node->left);
    }
    return 1+ max(depth(Node->left),depth(Node->right));

}
int getDia(TreeNode* root){
    int l,r;
    (root->left==NULL)?(l = 0) : l = depth(root->left); 
    (root->right==NULL)?(r = 0) : r = depth(root->right); 
    return l+r;
}
void inorder(TreeNode * node){
    if(node==NULL) return;
    
    inorder(node->left);
    ans = max(ans,getDia(node));
    inorder(node->right);
}
    int diameterOfBinaryTree(TreeNode* root) {
        // if(root->left==NULL && root->right==NULL) return 1;
        inorder(root);    
        return ans;
    }
};