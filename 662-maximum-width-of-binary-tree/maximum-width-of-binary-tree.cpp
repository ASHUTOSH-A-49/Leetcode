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
        if (root == nullptr) return 0;

        int maxWidth = 0;
        // Queue stores pairs of {TreeNode*, Position_Index}
        queue<pair<TreeNode*, unsigned long long>> q; 
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            unsigned long long levelMinIdx = q.front().second; // First node index in this level
            unsigned long long firstIdx = 0, lastIdx = 0;
            int validNodesCount = 0;
            for (int i = 0; i < size; i++) {
                // Normalize index to prevent integer overflow
                unsigned long long currIdx = q.front().second - levelMinIdx;
                TreeNode* node = q.front().first;
                q.pop();
                // Track indices for width calculation
                if (i == 0) firstIdx = currIdx;
                if (i == size - 1) lastIdx = currIdx;
                validNodesCount++;

                if (node->left) {
                    q.push({node->left, 2 * currIdx});
                }
                if (node->right) {
                    q.push({node->right, 2 * currIdx + 1});
                }
            }

            if (validNodesCount >= 1) {
                int currentWidth = lastIdx - firstIdx + 1;
                maxWidth = max(maxWidth, currentWidth);
            }
        }

        return maxWidth;
    }
};