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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head == NULL){
            return {-1,-1};
        }
        vector<int>ans;
        ListNode* prev=head;
        ListNode* curr=head->next;
        int i=1;
        while(curr !=NULL && curr->next !=NULL){
            if(curr->val > prev->val && curr->val > curr->next->val){
                ans.push_back(i);
            }
            if(curr->val < prev->val && curr->val < curr->next->val){
                ans.push_back(i);
            }
            curr=curr->next;
            prev=prev->next;
            i++;
        }
        if(ans.size()<2){
            return {-1,-1};
        }
        int mini=INT_MAX;
        for(int j=1;j<ans.size();j++){
            mini=min(mini,ans[j]-ans[j-1]);
        }
        int maxi=ans[ans.size()-1]-ans[0];
        return {mini,maxi};
    }
};