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
    ListNode* partition(ListNode* head, int x) {
        ListNode* a=new ListNode(0);
        ListNode* k;
        k=a;
        ListNode* b=new ListNode(0);
        ListNode* p;
        p=b;
        ListNode* temp=head;
        while(temp!=NULL){
            if(temp->val<x){
                a->next=temp;
                a=a->next;
            }
            else{
                b->next=temp;
                b=b->next;
            }
            temp=temp->next;
        }
        b->next=NULL;
        a->next=p->next;
        return k->next;
    }
};