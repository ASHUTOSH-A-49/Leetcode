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
typedef pair<int,int> pii;
class Solution {
public:
pii solve(TreeNode* root,int & cnt){
    if(!root) return {0,0}; //val,nodes
    pii l = solve(root->left,cnt);
    pii r = solve(root->right,cnt);
    int val = l.first+r.first;
    int nodes = l.second+r.second;
    int check  = (val+root->val)/(nodes+1);
    if(check==root->val) cnt++;
    return {val+root->val,nodes+1};
}
    int averageOfSubtree(TreeNode* root) {
        int cnt = 0;
        pii s = solve(root,cnt);
        return cnt;
    }
};