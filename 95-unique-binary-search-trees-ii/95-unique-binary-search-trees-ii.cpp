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
    vector<TreeNode*> solve(int left,int right){
        vector<TreeNode*>v;
        if(left>right){
            v.push_back(NULL);
            return v;
        }
        for(int i=left;i<=right;i++){
            auto a=solve(left,i-1);
            auto b=solve(i+1,right);
            for(auto k:a){
                for(auto j:b){
                    TreeNode* root=new TreeNode(i);
                    root->left=k;
                    root->right=j;
                    v.push_back(root);
                }
            }
        }
        return v;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};