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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right){
            return head;
        }
        if(left==1){
            ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next=head;
        int  c=right-left;
        while(c>=0 && curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            c--;
        }
        head->next=next;
        return prev;
        }
        ListNode* temp=head;
        int c=1;
        while(temp!=NULL && c<left-1){
            temp=temp->next;
            c++;
        }
        ListNode* prev=NULL;
        ListNode* curr=temp->next;
        ListNode* next=temp->next;
        c=right-left;
        while(c>=0 && curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            c--;
        }
        ListNode* p=temp->next;
        p->next=next;
        temp->next=prev;
        return head;
    }
};