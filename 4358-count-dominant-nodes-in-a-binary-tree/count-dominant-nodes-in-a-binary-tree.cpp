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
    int DFS(int & cnt,TreeNode* root){
        if(!root) return 0;
        if(!root->left && !root->right) {
            cnt++;
            return root->val;
        }
        int left = DFS(cnt,root->left), right = DFS(cnt,root->right);
        if(root->val >= max(left,right)) cnt++;
        return max({root->val,left,right});

    }
    int countDominantNodes(TreeNode* root) {
        if(!root) return 0;
        int cnt = 0;
        int maxi = DFS(cnt,root);
        return cnt;
    }
};