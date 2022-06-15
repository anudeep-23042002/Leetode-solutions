/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }
        Node* temp=head;
        while(temp!=NULL){
            Node* curr=new Node(temp->val);
            curr->next=temp->next;
            temp->next=curr;
            temp=curr->next;
        }
        Node* tem=head;
        Node* curr=head->next;
        int count=0;
        while(tem!=NULL){
            curr=tem->next;
            if(tem->random){
                curr->random=tem->random->next;
            }
            tem=curr->next;
        }
        curr=head;
        Node* h=head->next;
        Node* t;
        while(curr!=NULL){
            t=curr->next;
            curr->next=t->next;
            if(curr->next){
                t->next=curr->next->next;
            }
            curr=curr->next;
        }
        return h;
    }
};