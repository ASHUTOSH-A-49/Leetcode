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
void flatBT(TreeNode* root,TreeNode*&tail){
    if(root==NULL) return;
    TreeNode* leftNode = root->left;
    TreeNode* rightNode = root->right;
    if (tail != nullptr) {
            tail->left = nullptr;
            tail->right = root;
    }
    tail = root;
    flatBT(leftNode,tail);
    flatBT(rightNode,tail);
}
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        TreeNode* tail = nullptr;
        flatBT(root, tail);
    }
};