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

    void reorderList(ListNode* head) {
        if(head ==NULL || head->next ==NULL){
            return;
        }

       ListNode* slow=head;
       ListNode* fast=head;
       ListNode* prev=NULL;
       while(fast != NULL && fast->next !=NULL){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
       }
       prev->next=NULL;

       slow=reverse(slow);
       ListNode* temp=head;
        while(slow != NULL && temp!=NULL){
          ListNode* list=temp->next;
          temp->next=slow;
          slow=slow->next;


          if(list==NULL){
            return;
          }
          
          temp->next->next=list;
          temp=list;
        }
    }
};