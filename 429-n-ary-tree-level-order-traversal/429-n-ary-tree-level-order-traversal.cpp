/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>v;
        if(root==NULL){
            return v;
        }
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int y=q.size();
            vector<int>p;
            for(int b=0;b<y;b++){
                auto a=q.front();
                q.pop();
                p.push_back(a->val);
                for(auto i:a->children){
                    if(i!=NULL)
                        q.push(i);
                }
            }
            v.push_back(p);
        }
        return v;
    }
};