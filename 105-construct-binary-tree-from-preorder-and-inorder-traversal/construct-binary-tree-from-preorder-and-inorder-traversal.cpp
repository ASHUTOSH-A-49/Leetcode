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
//OPTIMISATION 1: use hashmap to reduce find time complexity
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0;i<inorder.size();i++) hash[inorder[i]] = i;
        TreeNode* root = new TreeNode(preorder[0]); 
        if(preorder.size()==1) return root;
        int ind = hash[root->val];  //reduce TC from O(N2) to O(N)
        TreeNode *left = nullptr, *right = nullptr;
        if (ind > 0) {
            vector<int> LeftPre(preorder.begin() + 1, preorder.begin() + ind + 1);
            vector<int> LeftIn(inorder.begin(), inorder.begin() + ind);
            left = buildTree(LeftPre, LeftIn);
        }
        if (ind < inorder.size() - 1) {
            vector<int> RightPre(preorder.begin() + 1 + ind, preorder.begin() + preorder.size());
            vector<int> RightIn(inorder.begin() + ind + 1, inorder.begin() + inorder.size());
            right = buildTree(RightPre, RightIn);
        }
        root->left = left;
        root->right = right;
        return root;
    }
};