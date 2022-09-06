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
    bool tree(TreeNode* root){
        if(root==NULL){
            return false;
        }
        bool f=true;
        bool t=true;
        if(!tree(root->left)){
            f=false;
            root->left=NULL;
        }
        if(!tree(root->right)){
            t=false;
            root->right=NULL;
        }
        if(root->val==1 || f || t){
            return true;
        }
        return false;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(!tree(root)){
            return NULL;
        }
        return root;
    }
};