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
    vector<vector<int>> ans;
void level(queue <TreeNode*> & q){
    while(!q.empty()){
        int n = q.size();
        vector<int> level;
        for(int i = 0;i<n;i++){
            TreeNode *Node = q.front();
            q.pop();
            if(Node->left!=NULL) q.push(Node->left);
            if(Node->right!=NULL) q.push(Node->right);
            level.push_back(Node->val);
        }
        ans.push_back(level);
        
    }
}
    int maxDepth(TreeNode* root) {
        queue<TreeNode*>q;
        if(root==NULL) return ans.size();
        q.push(root);
        level(q);
        return ans.size();
    }
};