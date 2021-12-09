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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //Base Case
        if(head == NULL){
            return head;
        }
        //Recursive Case
        int count = 1;
        ListNode * curr = head, * prev=NULL, * next=NULL;
        //Confirm remaining length >=k
        int remLen=0;
        while(curr!=NULL and remLen<k){
            curr=curr->next;
            remLen++;
        }
        if(remLen<k){
            return head;
        }
        curr=head;
        while(curr!=NULL && count<=k){
            next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }

        if(next!=NULL){
            head->next=reverseKGroup(next,k);
        }
        
        return prev;
    }
};