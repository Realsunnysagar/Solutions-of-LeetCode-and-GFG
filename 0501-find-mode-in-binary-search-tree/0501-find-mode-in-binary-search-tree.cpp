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
    int maxCnt = 0, cnt = 0;
    int preVal;
    bool hasPrev = false;
    vector<int> ans;
    void inorder(TreeNode* root){
        if(!root) return;

        inorder(root->left);

        if(hasPrev && preVal == root->val){
            cnt++;
        }else{
            cnt = 1;
        }

        if(cnt > maxCnt){
            maxCnt = cnt;
            ans = {root->val};
        }else if(cnt == maxCnt){
            ans.push_back(root->val);
        }

        preVal = root->val;
        hasPrev = true;

        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;
    }
};