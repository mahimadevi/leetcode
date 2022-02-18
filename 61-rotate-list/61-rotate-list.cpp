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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL or head->next==NULL) return head;
        
        int length=1;
        ListNode* tail=head;
        while(tail->next != NULL)  //to find the length of linkedlist
        {
            tail=tail->next;
            length++;
        }
        k = k % length;
        if(k==0) return head;
        
        ListNode* newhead=head;
        ListNode* newtail=head;
        while(length>k)
        {
            newtail = newhead;
            newhead = newhead -> next;
            length--;
        }
        tail->next=head;
        newtail->next=NULL;
        
        return newhead;
    }
};