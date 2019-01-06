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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<int> vecI;
        vector<vector<int>> vecV;
        if(root == NULL)
            return vecV;
        if(root->left == NULL && root->right == NULL){
            vecI.push_back(root->val);
            vecV.push_back(vecI);
            return vecV;
        }
            
        else if(root->right != NULL && root->left == NULL){
            vecI.push_back(root->val);
            vecV =levelOrderBottom(root->right);
            vecV.push_back(vecI);
            return vecV;
        }
        else if(root->left != NULL && root->right == NULL){
            vecI.push_back(root->val);
            vecV =levelOrderBottom(root->left);
            vecV.push_back(vecI);
            return vecV;
        }
        
        auto vecL = levelOrderBottom(root->left);
        auto vecR = levelOrderBottom(root->right);
        
        if(vecL.size() > vecR.size()){
            int dif = vecL.size() - vecR.size();
            vecV.insert(vecV.end(), vecL.begin(), vecL.begin() + dif);
            for(int i = 0; i < vecR.size(); i ++){
                vecI = vecL[i+dif];
                vecI.insert(vecI.end(), vecR[i].begin(), vecR[i].end());
                vecV.push_back(vecI);
                vecI.clear();
            }
        }
        else if(vecL.size() < vecR.size()){
            int dif = vecR.size() - vecL.size();
            vecV.insert(vecV.end(), vecR.begin(), vecR.begin() + dif);
            for(int i = 0; i < vecL.size(); i++){
                vecI = vecL[i];
                vecI.insert(vecI.end(), vecR[i+dif].begin(), vecR[i+dif].end());
                vecV.push_back(vecI);
                vecI.clear();
            }
        }
        else if(vecL.size() == vecR.size()){
            for(int i = 0; i < vecL.size(); i++){
                vecI = vecL[i];
                vecI.insert(vecI.end(), vecR[i].begin(), vecR[i].end());
                vecV.push_back(vecI);
                vecI.clear();
            }
            vecV.insert(vecV.end(), vecR.begin() + vecL.size(), vecR.end());
        }
        vecI.push_back(root->val);
        vecV.push_back(vecI);
        return vecV;
    }
};