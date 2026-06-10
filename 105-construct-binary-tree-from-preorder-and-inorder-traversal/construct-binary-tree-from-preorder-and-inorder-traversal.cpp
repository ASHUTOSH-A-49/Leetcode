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
//OPTIMISATION 2: use pointers instead of subarrays to reduce SC from O(N2) to O(N)
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0;i<inorder.size();i++) hash[inorder[i]] = i;
        return makeTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);

        
        // TreeNode* root = new TreeNode(preorder[0]); 
        // if(preorder.size()==1) return root;
        // int ind = hash[root->val];  //reduce TC from O(N2) to O(N)
        // TreeNode *left = nullptr, *right = nullptr;
        // if (ind > 0) {
        //     vector<int> LeftPre(preorder.begin() + 1, preorder.begin() + ind + 1);
        //     vector<int> LeftIn(inorder.begin(), inorder.begin() + ind);
        //     left = buildTree(LeftPre, LeftIn);
        // }
        // if (ind < inorder.size() - 1) {
        //     vector<int> RightPre(preorder.begin() + 1 + ind, preorder.begin() + preorder.size());
        //     vector<int> RightIn(inorder.begin() + ind + 1, inorder.begin() + inorder.size());
        //     right = buildTree(RightPre, RightIn);
        // }
        // root->left = left;
        // root->right = right;
        // return root;
    }

    TreeNode* makeTree(vector<int>& preorder, int preStart, int preEnd, 
                     vector<int>& inorder, int inStart, int inEnd){
        if (preStart > preEnd || inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]); 
        if (preStart == preEnd) return root;
        int ind = hash[root->val];  //reduce TC from O(N2) to O(N)
        int leftTreeSize = ind - inStart;
        root->left = makeTree(preorder, preStart + 1, preStart + leftTreeSize, 
                            inorder, inStart, ind - 1);              
        root->right = makeTree(preorder, preStart + leftTreeSize + 1, preEnd, 
                             inorder, ind + 1, inEnd);
        return root;
    }
};