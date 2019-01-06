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
    bool isBalanced(TreeNode* root){
        if(root == NULL)
            return true;
        else if(isBalanced(root->left) && isBalanced(root->right) && abs(treeHeight(root->left) - treeHeight(root->right)) <=1) 
            return true;
        return false;
    }
    int treeHeight(TreeNode* root){
        if(root == NULL)
            return 0;
        return max(treeHeight(root->left), treeHeight(root->right)) + 1;
    }
};