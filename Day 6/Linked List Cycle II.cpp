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
    ListNode *detectCycle(ListNode *head) {
        bool cycleFound=false;
        if(head==NULL||head->next==NULL){
            return NULL;
        }
        ListNode *fast=head,*slow=head;
        while(fast->next and fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                cycleFound=true;
                break;
            }
        }
        if(cycleFound){
            fast=head;
            while(fast->next and fast!=slow){
                slow=slow->next;
                fast=fast->next;
            }
            return fast;
        }
        return NULL;
    }
};