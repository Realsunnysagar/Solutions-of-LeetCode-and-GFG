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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode *cur = root;
        int ans = -1;
        int cnt = 0;
        while(cur != NULL){
            if(cur->left == NULL){ 
                cnt++;
                if(cnt == k)
                    ans = cur->val;
                cur = cur->right;
            }
            else{
                TreeNode* lastRight = cur->left;
                // iterated till the last right node of left subtree
                while(lastRight->right != NULL && lastRight->right != cur){
                    lastRight = lastRight->right;
                }

                if(lastRight->right == NULL){
                    lastRight->right = cur;
                    cur = cur->left;
                }else{
                    lastRight->right = NULL;
                    cnt++;
                    if(cnt == k) ans = cur->val;
                    cur = cur->right;
                }
            }
        }
        return ans;
    }
};