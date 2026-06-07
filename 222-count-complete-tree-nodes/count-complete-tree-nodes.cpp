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
void solve(TreeNode* root,map<TreeNode*,int> & m){
    if(root==NULL) return;
    m[root]++;
    solve(root->left,m);
    solve(root->right,m);
}
    int countNodes(TreeNode* root) {
        map<TreeNode*,int> m;
        solve(root,m);
        return (int)m.size();
    }
};