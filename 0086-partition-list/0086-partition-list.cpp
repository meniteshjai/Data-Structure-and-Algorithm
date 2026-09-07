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
        ListNode* temp=head;
        ListNode* first=new ListNode(-1);
        ListNode* second=new ListNode(-1);
        ListNode* fp=first;
        ListNode* sp=second;
        while(temp){
            if(temp->val < x){
                fp->next=temp;
                fp=fp->next;
            }
            else{
                sp->next=temp;
                sp=sp->next;
            }
            temp=temp->next;
        }
        sp->next=NULL;
        fp->next=second->next;
        return first->next;
    }
};