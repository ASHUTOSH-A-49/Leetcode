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
TreeNode *left = nullptr, *right = nullptr,*prev = nullptr;
void delNode(TreeNode*root,int key){
    if(!root) return;
    if(key==root->val){
        left = root->left;
        right = root->right;
        return;
    }
    if(key>root->val){
        prev = root;
        delNode(root->right,key);
    } 

    else{
        prev = root;
        delNode(root->left,key);
    } 
}
bool SearchNode(TreeNode* root,int val){
    if(!root) return false;
    if(root->val== val) return true;
    if (val > root->val) return SearchNode(root->right, val);
    return SearchNode(root->left, val);
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        left = nullptr;
        right = nullptr;
        prev = nullptr;
        
        bool Search = SearchNode(root,key);
        if(Search){
            delNode(root,key);
            if(left==nullptr && right==nullptr){
                if (prev == nullptr) return nullptr; // Tree had only one node
                //else leafnode
                if (key < prev->val) prev->left = nullptr; 
                else prev->right = nullptr;
                return root;
            } 
            
            if (left == nullptr) {
                if (prev == nullptr) return right; // Deleting the root node
                if (key < prev->val) prev->left = right;
                else prev->right = right;
                return root;
            }
            if (right == nullptr) {
                if (prev == nullptr) return left; // Deleting the root node
                if (key < prev->val) prev->left = left;
                else prev->right = left;
                return root;
            }

            // Scenario 4: Node has two children (Attach left tree to the leftmost position of the right tree)
            TreeNode* curr = right;
            while (curr->left != nullptr) {
                curr = curr->left;
            }
            curr->left = left;

            if (prev == nullptr) return right; // Deleting the root node
            if (key < prev->val) prev->left = right;
            else prev->right = right;
             
        }
        return root;
        
        
    }
};