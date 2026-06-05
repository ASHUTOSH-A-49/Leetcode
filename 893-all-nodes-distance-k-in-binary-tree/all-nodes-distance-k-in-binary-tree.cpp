/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void ParentsMark(TreeNode* root, unordered_map<TreeNode*,TreeNode*> & parents,TreeNode* target){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left){
                parents[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right){
                parents[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parents;
        ParentsMark(root,parents,target);

        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        //BFS APPROACH - move radially by 1 step at each time and push into queue and then update curr level and when curr level = k break and return queue elements as 
        
        int currlvl = 0;
        while(!q.empty()){
            int siz = q.size();
            if(currlvl++ == k) break;
            for(int i = 0;i<siz;i++){
                TreeNode* node = q.front();q.pop();
                if(node->left && !visited[node->left]){
                    visited[node->left] = true;
                    q.push(node->left);
                }
                if(node->right && !visited[node->right]){
                    visited[node->right] = true;
                    q.push(node->right);
                }
                if(parents[node] && !visited[parents[node]]){
                    visited[parents[node]] = true;
                    q.push(parents[node]);
                }
            }
        }
        vector<int> res;
        while(!q.empty()){
            TreeNode* curr = q.front();q.pop();
            res.push_back(curr->val);
        }
        return res;

    }
};