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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>v;
        if(root==NULL){
            return v;
        }
        q.push(root);
        while(!q.empty()){
            vector<int>d;
            int n=q.size();
            for(int i=0;i<n;i++){
                auto k=q.front();
                q.pop();
                d.push_back(k->val);
                if(k->left!=NULL){
                    q.push(k->left);
                }
                if(k->right!=NULL){
                    q.push(k->right);
                }
            }
            v.push_back(d);
            d.clear();
        }
        return v;
    }
};