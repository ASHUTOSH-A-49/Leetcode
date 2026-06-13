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
    TreeNode* createBST(vector<int>& preorder, int& i, int maxr) {
        if (i == preorder.size() || preorder[i] > maxr) return nullptr;
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = createBST(preorder, i, root->val);
        root->right = createBST(preorder, i, maxr);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return createBST(preorder, i, INT_MAX);
    }
};