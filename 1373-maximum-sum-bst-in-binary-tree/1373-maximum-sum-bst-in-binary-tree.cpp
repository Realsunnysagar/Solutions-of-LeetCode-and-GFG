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
    int minNode, maxNode;
    long long sum, maxSum;
    // bool isBST;

    NodeValue(int minNode, int maxNode, long long sum, long long maxSum){
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->sum = sum;
        this->maxSum = maxSum;
    }
 };
class Solution {
public:
    // int maxSum = 0;
    NodeValue maxSumBSTSubtreeHelper(TreeNode* root){
        if (root == NULL) return NodeValue(INT_MAX, INT_MIN, 0, 0);

        auto left = maxSumBSTSubtreeHelper(root->left);
        auto right = maxSumBSTSubtreeHelper(root->right);

        if(left.maxNode < root->val && root->val < right.minNode){
            long long sum = left.sum + right.sum + root->val;
            long long best = max({left.maxSum, right.maxSum, sum});
            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), sum, best);
        }
        return NodeValue(INT_MIN, INT_MAX, 0, max(left.maxSum, right.maxSum));
    }
    int maxSumBST(TreeNode* root) {
        return (int)max(0LL, maxSumBSTSubtreeHelper(root).maxSum);
    }
};