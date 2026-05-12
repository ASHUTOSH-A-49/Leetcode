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
//recursive solution
vector<int> ans;
void solve(TreeNode* node,int level){
    if(node==NULL) return;
    if(level==ans.size()) ans.push_back(node->val);
    solve(node->right,level+1);
    solve(node->left,level+1);
}

    vector<int> rightSideView(TreeNode* root) {
        solve(root,0);
       return ans;
    }
};