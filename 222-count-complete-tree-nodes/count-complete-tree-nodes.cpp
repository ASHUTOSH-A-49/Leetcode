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
int getHeight(TreeNode* node) {
    int height = 0;
    while (node) {
        height++;
        node = node->left;
    }
    return height;
}
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lH = getHeight(root->left);
        int rH = getHeight(root->right);

        if(lH==rH){
            return (1<<lH) + countNodes(root->right);
            //BT is complete and all level filled complete
        }else{
            return (1<<rH) + countNodes(root->left);
            // leftmost levels filled hence all filled completely till right height only 
        }
        return 1;
    }
};