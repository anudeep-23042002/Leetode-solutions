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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int>v;
        if(root==NULL){
            return v;
        }
        q.push(root);
        TreeNode* curr=root;
        while(!q.empty()){
            int m=q.size();
            for(int i=0;i<m;i++){
                if(i==0){
                    curr=q.front();
                    v.push_back(curr->val);
                    q.pop();
                    if(curr->right!=NULL){
                        q.push(curr->right);
                    }
                    if(curr->left!=NULL){
                        q.push(curr->left);
                    }
                }
                else{
                    curr=q.front();
                     if(curr->right!=NULL){
                        q.push(curr->right);
                    }
                    if(curr->left!=NULL){
                        q.push(curr->left);
                    }
                    q.pop();
                }
            }
        }
        return v;
    }
};