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
    void traverse(TreeNode* root,vector<int> & nodes){
        if(!root) return;
        traverse(root->left,nodes);
        nodes.push_back(root->val);
        traverse(root->right,nodes);
    }
    bool BSFind(vector<int> nodes,int target,int i){
        
        int low = i,high = nodes.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nodes[mid]==target) return true;
            else if(nodes[mid]<target) low = mid+1;
            else high = mid-1;
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> nodes;
        traverse(root,nodes);
        int n = nodes.size();
        for(int i:nodes) cout<<i<<" ";
        cout<<endl;
        for(int i = 0;i<n;i++){
            if(BSFind(nodes,k-nodes[i],i+1)) return true;
        }
        return false;
    }
};