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
    int count;
    void solve(TreeNode* root,int ma){
        if(root->val>=ma){
            count++;
            ma=root->val;
        }
        if(root->left!=NULL){
            solve(root->left,ma);
        }
        if(root->right!=NULL){
            solve(root->right,ma);
        }
        return;
    }
    int goodNodes(TreeNode* root) {
        count=0;
        solve(root,root->val);
        return count;
    }
};