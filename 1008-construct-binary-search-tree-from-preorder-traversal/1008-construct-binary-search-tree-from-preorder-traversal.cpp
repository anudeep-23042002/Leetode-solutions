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
    TreeNode* bst(vector<int>preorder,vector<int>inorder,int l,int r,int a,int b,int n){
        if(l>r){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[l]);
        int index=l;
        for(int i=a;i<=b;i++){
            if(inorder[i]==preorder[l]){
                index=i;
                break;
            }
        }
        root->left=bst(preorder,inorder,l+1,l+index-a,a,index-1,n);
        root->right=bst(preorder,inorder,l+index-a+1,r,index+1,b,n);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        auto inorder=preorder;
        sort(inorder.begin(),inorder.end());
        int n=inorder.size();
        return bst(preorder,inorder,0,n-1,0,n-1,n);
    }
};