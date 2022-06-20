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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        ListNode* even=temp;
        ListNode* temp2=head->next;
        ListNode* odd=head;
        ListNode* temp1;
        while(odd!=even && odd!=temp2){
            temp->next=odd->next;
            temp1=odd->next->next;
            odd->next->next=NULL;
            odd->next=temp1;
            odd=odd->next;
            temp=temp->next;
        }
        return head;
    }
};