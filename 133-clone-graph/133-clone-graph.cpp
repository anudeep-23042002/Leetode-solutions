/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return NULL;
        }
        queue<Node*>q;
        map<Node*,Node*>m;
        q.push(node);
        Node* f=node;
        while(!q.empty()){
            int w=q.size();
            for(int z=0;z<w;z++){
                Node* k = q.front();
                q.pop();
                if(m.count(k)>0){
                    continue;
                }
                else{
                    Node* p=new Node(k->val);
                    if(k==node){
                        f=p;
                    }
                    m[k]=p;
                    for(auto i:k->neighbors){
                        q.push(i);
                    }
                }
            }
        }
        q.push(node);
        map<Node*,int>r;
        while(!q.empty()){
            int w=q.size();
            for(int z=0;z<w;z++){
                Node* k = q.front();
                q.pop();
                if(r.count(k)>0){
                    continue;
                }
                else{
                    auto p=m[k];
                    for(auto i:k->neighbors){
                        p->neighbors.push_back(m[i]);
                        q.push(i);
                    }
                    r[k]=1;
                }
            }
        }
        return f; 
    }
};