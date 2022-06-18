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
    int kthSmallest(TreeNode* root, int t) {
        TreeNode* temp=root;
        stack<TreeNode*>s;
        while(temp!=NULL){
            s.push(temp);
            temp=temp->left;
        }
        int count=0;
        TreeNode* curr=temp;
        while(!s.empty() && curr==NULL){
            auto k=s.top();
            s.pop();
            count+=1;
            if(count==t){
                return k->val;
            }
            curr=k->right;
            while(curr!=NULL){
                s.push(curr);
                curr=curr->left;
            }
        }
        return -1;
    }
};