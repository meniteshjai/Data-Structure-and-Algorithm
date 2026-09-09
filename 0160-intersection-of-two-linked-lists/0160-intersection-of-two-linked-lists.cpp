/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        int a=1;
        int b=1;
        while(tempA){
            a++;
            tempA=tempA->next;
        }
        while(tempB){
            b++;
            tempB=tempB->next;
        }
        tempA=headA;
        tempB=headB;
        if(b>a){
            for(int i=0;i<b-a;i++){
                tempB=tempB->next;
            }
        }
        else{
            for(int i=0;i<a-b;i++){
                tempA=tempA->next;
            }
        }    
        while(tempA && tempB){
            if(tempA==tempB){
               return tempA; 
            }
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return NULL;
    }
};