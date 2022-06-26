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
    ListNode* reverse(ListNode* head){
        ListNode *curr,*prev,*next;
        prev=NULL;
        curr=head;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head->next==NULL){
            return head;
        }
        ListNode* headtemp=head,* temp1,* temp=head,* prev,*pre;
        pre=NULL;
        while(temp!=NULL){
            int j=k;
            headtemp=temp;
            while(j>1 && temp->next!=NULL){
                temp=temp->next;
                j-=1;
            }
            if(j!=1){
                pre->next=headtemp;
                return head;
            }
            prev=temp;
            temp=temp->next;
            prev->next=NULL;
            temp1=reverse(headtemp);
            if(headtemp==head){
                head=temp1;
            }
            if(pre){
                pre->next=temp1;
            }
            pre=headtemp;
        }
        return head;
    }
};