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
    
    void Genpath(vector<TreeNode*> & path,TreeNode* root, TreeNode * n,bool & found){
        if(root==NULL || found) return;
        path.push_back(root);
        if(root->val==n->val){
            found = true;
            return;
        }
        Genpath(path, root->left,n,found);
        if(found) return;
        Genpath(path, root->right,n,found);
        if(found) return;
        path.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //brute force
        vector<TreeNode*> pathp,pathq;
        bool check = false;
        Genpath(pathp,root,p,check);
        check = false;
        Genpath(pathq,root,q,check);
        for(TreeNode* i:pathp){
            cout<<i->val<<" ";
        }
        cout<<endl;
        for(TreeNode*  i:pathq){
            cout<<i->val<<" ";
        }
        cout<<endl;
        TreeNode* result = root;
        int m = pathp.size();
        int n = pathq.size();
        int j = min(m,n);
        for(int i = 0;i<j;i++){
            TreeNode* np = pathp[i];
            TreeNode* nq = pathq[i];
            if(np->val==nq->val){
                result = np;
            }else{
                break;
            }
        }

        return result;
        
    }
};