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
vector<vector<int>> nodes;
void level(queue <TreeNode*> & q){
    while(!q.empty()){
        int n = q.size();
        vector<int> level;
        for(int i = 0;i<n;i++){
            TreeNode *Node = q.front();
            q.pop();
            if(Node!=NULL){
                q.push(Node->left);
                q.push(Node->right);
                level.push_back(Node->val); 
            }else{
                level.push_back(-101);
            }
            
        }
        nodes.push_back(level);
        
    }
}
    bool isSymmetric(TreeNode* root) {
        vector<int> rightNodes;
        vector<int> leftNodes;
        queue<TreeNode*>q;
        q.push(root);
        level(q);
        for(vector<int> v: nodes){
            for(int i = 0;i<v.size();i++){
                leftNodes.push_back(v[i]);
            }
        }
        for(vector<int> v: nodes){
            for(int i = v.size()-1;i>=0;i--){
                rightNodes.push_back(v[i]);
            }
        }
        for(int i:leftNodes) cout<<i<<" ";
        cout<<endl;
        for(int i:rightNodes) cout<<i<<" ";
        cout<<endl;
        for(int i = 0;i<leftNodes.size();i++){
            if(leftNodes[i]!=rightNodes[i]) return false;
        }    
        return true;
    }
};