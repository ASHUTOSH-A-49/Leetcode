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
//BRUTE - flatten into inorder vector and take 2 node pointers to get faulty nodes and swap
void inorderTrav(TreeNode* root,vector<TreeNode*> & nodes){
    if(!root) return;
    inorderTrav(root->left,nodes);
    nodes.push_back(root);
    inorderTrav(root->right,nodes);
}
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> nodes;
        inorderTrav(root,nodes);
        TreeNode* n1 = nullptr, *n2 = nullptr;
        int ind = nodes.size()-1;
        for(int i  = 0;i<ind;i++){
            if(nodes[i]->val > nodes[i+1]->val){
                if(n1==nullptr){
                    n1 = nodes[i];
                    n2 = nodes[i + 1]; 
                }
                else n2 = nodes[i+1];
            }
        }
        if (n1 && n2) {
            int temp = n2->val;
            n2->val = n1->val;
            n1->val = temp;
        }

    }
};