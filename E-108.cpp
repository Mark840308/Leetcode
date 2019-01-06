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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *r;
        if(nums.size() == 0)
            return NULL;
        else if(nums.size() == 1)
            return(new TreeNode(nums[0]));
        else{
            int piv = nums.size()/2;
            r = new TreeNode(nums[piv]);
            vector<int>::iterator middle = nums.begin() + piv;
            vector<int> pre(nums.begin(), middle);
            vector<int> post(middle+1, nums.end());
            r->left = sortedArrayToBST(pre);
            r->right = sortedArrayToBST(post);
        }
        return r;
    }
};