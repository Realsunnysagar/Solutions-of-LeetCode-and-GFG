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
 class BSTIterator{
private:
    stack<TreeNode*> myStack;
    // reverse-> true then before
    // reverse -> false then next
    bool reverse = true;
public:
    BSTIterator(TreeNode* root, bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }

    int next(){
        TreeNode* tmpNode = myStack.top();
        myStack.pop();
        if(!reverse) pushAll(tmpNode->right);
        else pushAll(tmpNode->left);
        return tmpNode->val;
    }

    void pushAll(TreeNode* node){
        for( ; node != NULL ;){
            myStack.push(node);
            if(reverse == true) node = node->right;
            else node = node->left;
        }
    }
 };
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        
        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next(); //r.before();

        while(i < j){
            if(i+j == k) return true;
            else if(i + j < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};