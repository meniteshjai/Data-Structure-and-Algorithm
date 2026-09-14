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
    ListNode* swapPairs(ListNode* head) {
        int count=1;
        ListNode* temp=head;
        while(temp != NULL && count<=2){
            temp=temp->next;
            count++;
        }
        if(count==3){
            ListNode* prev=NULL;
            ListNode* curr=head;
            ListNode* forward=NULL;
            int i=1;
            while(i<=2){
                forward=curr->next;
                curr->next=prev;
                prev=curr;
                curr=forward;
                i++;
            }
            ListNode* recursion=swapPairs(forward);
            head->next=recursion;
            return prev;
        }
        else{
            return head;
        }
        return head;
    }
};