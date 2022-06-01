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
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* head=new ListNode(0);
        ListNode* tem=head;
        int sum=0,carry=0;
        while(temp1!=NULL && temp2!=NULL){
            sum=temp1->val+temp2->val+carry;
            carry=0;
            if(sum>=10){
                carry=1;
                sum=sum%10;
            }
            ListNode* temp=new ListNode(sum);
            tem->next=temp;
            tem=temp;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1!=NULL){
            sum=temp1->val+carry;
            carry=0;
            if(sum>=10){
                carry=1;
                sum=sum%10;
            }
            ListNode* temp=new ListNode(sum);
            tem->next=temp;
            tem=temp;
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            sum=temp2->val+carry;
            carry=0;
            if(sum>=10){
                carry=1;
                sum=sum%10;
            }
            ListNode* temp=new ListNode(sum);
            tem->next=temp;
            tem=temp;
            temp2=temp2->next;
        }
        if(carry>0){
            ListNode* temp=new ListNode(carry);
            tem->next=temp;
            tem=temp;
        }
        return head->next;
    }
};