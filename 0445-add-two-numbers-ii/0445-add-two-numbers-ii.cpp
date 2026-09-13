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
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr != NULL){
            ListNode* forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverse(l1);
        l2=reverse(l2);
        ListNode* sum=new ListNode(-1);
        ListNode* temp=sum;
        int carry=0;
        while(l1 || l2 || carry){
            int a=l1 ? l1->val : 0;
            int b=l2 ? l2->val : 0;
            int sum=a+b+carry;
            int digit=sum%10;
            carry=sum/10;
            temp->next=new ListNode(digit);
            temp=temp->next;
            l1=l1 ? l1->next :0;
            l2=l2 ? l2->next :0;
        }
        if(carry){
            temp->next=new ListNode(carry);
        }
        return reverse(sum->next);
    }
};