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
    ListNode* iterative(ListNode* l1, ListNode* l2){
        auto ans=new ListNode(-1);
        auto it =ans;
        int c=0;
        while(l1 || l2 || c){
            int a= l1 ? l1->val : 0;
            int b= l2 ? l2->val : 0;
            int sum= a+b+c;
            int digit = sum%10;
            c=sum/10;

            it->next=new ListNode(digit);
            it=it->next;
            l1=l1 ? l1->next : 0;
            l2=l2 ? l2->next : 0;
        }
        return ans->next;
    }
    ListNode* my(ListNode* l1, ListNode* l2){
        int carry=0;
        ListNode* sum=new ListNode(0);
        ListNode* temp=sum;
        while(l1 || l2 || carry){
            int sum=carry;
            if(l1){
                sum=sum+(l1->val);
                l1=l1->next;
            }
            if(l2){
                sum=sum+(l2->val);
                l2=l2->next;
            }
            carry=sum/10;
            temp->next=new ListNode(sum % 10);
            temp=temp->next;
        }
        return sum->next;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      return my(l1,l2);
    }
};