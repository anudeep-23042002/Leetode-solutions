/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* getmid(ListNode* head,ListNode* end){
        ListNode* slow=head,*fast=head;
        while(fast!=NULL && fast!=end && fast->next!=end){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
     ListNode* merge( ListNode* left, ListNode* right){
         ListNode* head=new ListNode(0);
         ListNode* h=head;
         if(left==NULL){
             return right;
         }
         if(right==NULL){
             return left;
         }
         while(left!=NULL && right!=NULL){
             if(left->val<=right->val){
                 head->next=left;
                 left=left->next;
             }
             else{
                 head->next=right;
                 right=right->next;
             }
             head=head->next;
         }
         if(left!=NULL){
             head->next=left;
         }
         if(right!=NULL){
             head->next=right;
         }
         return h->next;
        
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return head;
        }
        ListNode* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        ListNode* mid=getmid(head,temp);
        ListNode* left=head;
        while(left!=mid && left!=NULL){
            left=left->next;
        }
        ListNode* right;
        if(left==NULL){
            right=left;
        }
        else{
            right=left->next;
            left->next=NULL;
        }
        ListNode* a=sortList(head);
        ListNode* b=sortList(right);
        return merge(a,b);
    }
};