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
    void flatten(TreeNode* root) {
        if(root==NULL){
            return;
        }
        stack<TreeNode*>s;
        s.push(root);
        TreeNode* h=new TreeNode(0);
        TreeNode* head=h;
        while(!s.empty()){
            auto temp=s.top();
            s.pop();
            if(temp->right!=NULL){
                s.push(temp->right);
            }
            if(temp->left!=NULL){
                s.push(temp->left);
            }
            temp->left=NULL;
            h->right=temp;
            h=h->right;
        }
        root=head;
        return;
    }
};