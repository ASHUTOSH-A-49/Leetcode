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
//level order traversal approach 
// int getDepth(TreeNode* root) {
//         if (root == NULL) return 0;
//         return 1 + max(getDepth(root->left), getDepth(root->right));
//     }

//     void fillTree(TreeNode* root, int currentDepth, int maxDepth) {
//         if (currentDepth == maxDepth) {
//             return;
//         }
//         if (root->left == NULL) {
//             root->left = new TreeNode(-101);
//         }
//         if (root->right == NULL) {
//             root->right = new TreeNode(-101);
//         }
//         fillTree(root->left, currentDepth + 1, maxDepth);
//         fillTree(root->right, currentDepth + 1, maxDepth);
//     }

//     vector<vector<int>> nodes;

//     void level(queue<TreeNode*>& q) {
//         while (!q.empty()) {
//             int n = q.size();
//             vector<int> currentLevel;
//             bool anyChildrenPushed = false;

//             for (int i = 0; i < n; i++) {
//                 TreeNode* Node = q.front();
//                 q.pop();
//                 if (Node != NULL) {
//                     currentLevel.push_back(Node->val);
//                     if (Node->left || Node->right) {
//                         q.push(Node->left);
//                         q.push(Node->right);
//                         anyChildrenPushed = true;
//                     }
//                 } else {
//                     currentLevel.push_back(-101);
//                 }
//             }

//             if (!currentLevel.empty()) {
//                 nodes.push_back(currentLevel);
//             }
//             if (!anyChildrenPushed) {
//                 break;
//             }
//         }
//     }

    int widthOfBinaryTree(TreeNode* root) {
        // MODIFIED INDEXING based SOLUTION:

        if(!root) return 0;
        int ans = 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(!q.empty()){
            int siz = q.size();
            int minid = q.front().second;
            int first,last;
            for(int i = 0;i<siz;i++){
                long long cur = q.front().second-minid;
                TreeNode* node = q.front().first;
                q.pop();
                if(i==0) first = cur;
                if(i==siz-1) last = cur;
                if(node->left){
                    q.push({node->left,cur*2+1});
                }
                if(node->right){
                    q.push({node->right,cur*2+2});
                }
                
            }
            ans= max(ans,last-first+1);
        }
        return ans;
    }
};