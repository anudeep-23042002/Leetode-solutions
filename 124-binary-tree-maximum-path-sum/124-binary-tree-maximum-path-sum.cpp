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
    int mas;
    int maxPathSum(TreeNode* root) {
        mas=INT_MIN;
        mas=max(mas,maxsum(root));
        return mas;
    }
    int maxsum(TreeNode* root){
        if(root==NULL){
            return INT_MIN;
        }
        if(root->left==NULL && root->right==NULL){
            mas=max(mas,root->val);
            return root->val;
        }
        int left_path=maxsum(root->left);
        int right_path=maxsum(root->right);
        if(root->val>0 && left_path>0){
            mas=max(mas,left_path+root->val);
        }
        if(root->val>0 && right_path>0){
            mas=max(mas,right_path+root->val);
        }
        mas=max(mas,max(left_path,right_path));
        if(left_path>=0 && right_path>=0){
            mas=max(mas,left_path+right_path+root->val);
        }
        
        return max(0,max(left_path,right_path))+root->val;
        }
};