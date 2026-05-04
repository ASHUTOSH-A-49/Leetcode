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
int ans = -1001;
int depthCost(TreeNode* Node){
    if (Node == NULL) return 0;
    int l = max(0,depthCost(Node->right));
    int r = max(0,depthCost(Node->left));
    ans = max({ans,Node->val+l+r});
    return Node->val + max(l,r);

}
    int maxPathSum(TreeNode* root) {
        depthCost(root);
        return ans;
    }
};