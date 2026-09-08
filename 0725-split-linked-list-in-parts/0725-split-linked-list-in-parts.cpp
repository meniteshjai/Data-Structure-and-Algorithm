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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int count=0;
        ListNode* temp=head;
        while(temp){
            count++;
            temp=temp->next;
        }
        int fixed=count/k;
        int extra=count%k;

        vector<ListNode*>ans(k,nullptr);
        temp=head;
        for(int i=0;i<k && temp;i++){
            ans[i]=temp;
            int actual=fixed+(extra-- >0 ? 1:0);
            for(int j=0;j<actual-1;j++){
                temp=temp->next;
            }
            ListNode* nextpointer=temp->next;
            temp->next=NULL;
            temp=nextpointer;
        }
        return ans;
    }
};