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
    void zigzagTrav(queue <TreeNode*> & q){
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        zigzagTrav(q);
        int n = ans.size();
        if(n>1){
            for(int i = 1;i<n;i+=2){
                vector<int> v = ans[i];
                reverse(v.begin(),v.end());
                ans[i] = v;
            }
        }
        return ans;
        

    }
};