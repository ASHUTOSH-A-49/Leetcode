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
pair<int,int> getRootVal(vector<vector<int>>& descriptions){
        map<int,int> isChild;
        for(vector<int> v:descriptions){
            isChild[v[0]] = 0;
            isChild[v[1]] = 0;
        }
        for(vector<int> v:descriptions){
            isChild[v[1]]++;
        }
        int rootval = 0;
        for(pair<int,int> p:isChild){
            if(p.second==0){
                rootval = p.first;
            }
        }
        return {rootval,(int)isChild.size()};
    }

    void solve(TreeNode* newroot, map<int, vector<vector<int>>>& adj, int siz, map<int,int>& visited){
        if(visited.size() == siz) return;
        int curr = newroot->val;
        visited[curr]++;
        
        for(vector<int> v : adj[curr]){
            TreeNode* node = new TreeNode(v[1]);
            if(v[2] == 1){
                newroot->left = node;
                solve(newroot->left, adj, siz, visited);
            } else {
                newroot->right = node;
                solve(newroot->right, adj, siz, visited);
            }
        }
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        auto [rval, siz] = getRootVal(descriptions);
        TreeNode* root = new TreeNode(rval);
        map<int,int> visited;
        map<int, vector<vector<int>>> adj;
        for(vector<int> v : descriptions) {
            adj[v[0]].push_back(v);
        }
        solve(root, adj, siz, visited);
        return root;

    }
};