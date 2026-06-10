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
map<int,int> hash;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0;i<inorder.size();i++) hash[inorder[i]] = i;
        return makeTree(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

   TreeNode* makeTree(vector<int>& postorder, int postStart, int postEnd, 
                     vector<int>& inorder, int inStart, int inEnd) {
        if (postStart > postEnd || inStart > inEnd) return nullptr;
        TreeNode* root = new TreeNode(postorder[postEnd]); 
        if (postStart == postEnd) return root;
        int ind = hash[root->val];  
        int leftTreeSize = ind - inStart;
        root->left = makeTree(postorder, postStart, postStart + leftTreeSize - 1, 
                              inorder, inStart, ind - 1);              
        root->right = makeTree(postorder, postStart + leftTreeSize, postEnd - 1, 
                               inorder, ind + 1, inEnd);
        return root;
    }
};