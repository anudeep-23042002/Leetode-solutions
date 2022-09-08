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
    TreeNode* tree(vector<int>in,vector<int>pre, int l,int r,int l1,int r1,int n){
        if(l>r){
            return NULL;
        }  
        if(l==r){
            TreeNode* root=new TreeNode(in[l]);
            return root;
        }
        TreeNode* root=new TreeNode(pre[l1]);
        int index=l;
        for(int i=l;i<=r;i++){
            if(in[i]==pre[l1]){
                index=i;
                break;
            }
        }
        root->left=tree(in,pre,l,index-1,l1+1,l1+index-l,n);
        root->right=tree(in,pre,index+1,r,l1+index-l+1,r1,n);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n=in.size();
        return tree(in,pre,0,n-1,0,n-1,n);
    }
};