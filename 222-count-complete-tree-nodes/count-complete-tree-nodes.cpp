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
int h = 0;
int leafs = 0;
bool checkleaf = false;
void solve(TreeNode* root,int level){
    level++;
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL){
        if(!checkleaf) h++;
        checkleaf = true;
        if(checkleaf && (level==h))leafs++;
    }
    if(!checkleaf) h++;
    solve(root->left,level);
    solve(root->right,level);
}
    int countNodes(TreeNode* root) {
        
        solve(root,0);
        cout<<h<<endl;
        cout<<leafs<<endl;
        int ans = 0;
        if(h==0) return ans;
        ans  = leafs;
        for(int i = 0;i<h-1;i++){
            ans+=(1<<i);
        }
        return ans;
    }
};