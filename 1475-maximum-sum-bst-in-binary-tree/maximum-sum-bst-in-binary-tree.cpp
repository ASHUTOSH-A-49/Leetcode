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

class NodeValue{
    public:
    int minNode, maxNode, sum;
    bool isBST;
    NodeValue(int minNode, int maxNode, int sum, bool isBST) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->sum = sum;
        this->isBST = isBST;
    }
    
};
class Solution {
private:
int globalMaxSum = 0;
NodeValue helper(TreeNode* root){
    if(!root) return NodeValue(INT_MAX, INT_MIN, 0, true); //handle null nodes;

    auto left = helper(root->left);
    auto right = helper(root->right);

    if (left.isBST && right.isBST && left.maxNode < root->val && root->val < right.minNode) {
        int currentSum = left.sum + right.sum + root->val;
        globalMaxSum = max(globalMaxSum, currentSum); // Update global maximum
        
        return NodeValue(
            min(root->val, left.minNode),
            max(root->val, right.maxNode),
            currentSum,
            true
        );
    }

    return NodeValue(INT_MIN, INT_MAX, 0, false);
}

public:
    int maxSumBST(TreeNode* root) {
        globalMaxSum = 0;
        helper(root);
        return globalMaxSum;
    }
};