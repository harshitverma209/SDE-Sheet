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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        ListNode* oddHead=head;
        ListNode* evenHead=head->next?head->next:NULL;
        while(oddHead->next){
            ListNode* evenNode=oddHead->next;
            oddHead->next=oddHead->next->next;
            evenNode->next=oddHead->next?oddHead->next->next:NULL;
            oddHead=oddHead->next?oddHead->next:oddHead;
        }
        oddHead->next=evenHead;
        return head;
    }
};