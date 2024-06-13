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
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=head;

        while(fast && fast->next){
           slow=slow->next;
           fast=fast->next->next; 
        }
        // Handles the case when the length of the linked list is odd by advancing slow one more step.
        if(fast != NULL && fast->next == NULL)
        slow=slow->next;
        ListNode* nextNode, *prevNode=NULL;
        while(slow && slow->next){
            nextNode=slow->next;
            slow->next=prevNode;
            prevNode=slow;
            slow=nextNode;
        }
        if(slow != NULL){
            slow->next = prevNode;
        }
        while(slow && prev){
            if(prev->val != slow->val){
                return false;
            }
                prev=prev->next;
                slow=slow->next;
        }
        return true;
    }
};