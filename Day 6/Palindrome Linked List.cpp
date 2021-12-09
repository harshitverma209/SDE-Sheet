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
    ListNode* reverseList(ListNode* head){
        if(head==NULL or head->next==NULL){
            return head;
        }
        ListNode* last=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return last;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL or head->next==NULL){
            return true;
        }
        ListNode *slow=head, *fast=head;
        while(fast->next and fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        slow->next=reverseList(slow->next);
        slow=slow->next;
        while(head and slow){
            if(head->val!=slow->val){
                return false;
            }
            head=head->next;
            slow=slow->next;
        }
        return true;
        
    }
};