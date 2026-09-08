/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:

    Node* solve(Node* head){
        if(!head){
            return NULL;
        }
        Node* it =head;
        Node* tail=it;
        while(it){
            if(it->child){
                Node* childTail=solve(it->child);
                Node* temp=it->next;

                it->next=it->child;
                it->next->prev=it;
                childTail->next=temp;

                if(temp){
                    temp->prev=childTail;
                }
                it->child=NULL;
            }
            tail=it;
            it=it->next;
        }
        return tail;
    }
    Node* flatten(Node* head) {
        solve(head);
        return head;
    }
};