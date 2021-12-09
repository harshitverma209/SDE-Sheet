/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return head;
        }
        Node *temp=head;
        while(temp!=NULL){
            Node *node=new Node(temp->val);
            node->next=temp->next;
            temp->next=node;
            temp=temp->next->next;
        }
        temp=head;
        Node *copiedHead=head->next;
        while(temp){
            Node* copiedNode=temp->next;
            copiedNode->random=temp->random?temp->random->next:NULL;
            temp=temp->next->next;
        }
        temp=head;
        Node* tempCopy=copiedHead;
        while(temp && tempCopy){
            temp->next=temp->next->next;
            tempCopy->next=tempCopy->next?tempCopy->next->next:NULL;
            temp=temp->next;
            tempCopy=tempCopy->next;
        }
        return copiedHead;
    }
};