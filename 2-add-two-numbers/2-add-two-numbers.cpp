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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp= new ListNode(0);
        ListNode* curr=temp;
        int carry=0;
        ListNode* head1=l1;
        ListNode* head2=l2;
        while(head1 != NULL || head2 != NULL){
            int x, y;
            if(head1 != NULL)
                x = head1 -> val;
            else x=0;
             if(head2 != NULL)
                y = head2 -> val;
            else
                y=0;
            int sum=carry+x+y;
            carry=sum/10;
            curr->next=new ListNode(sum%10);
            curr=curr->next;
            if (head1 != NULL) head1 = head1->next;
            if (head2 != NULL) head2 = head2->next;
        }
        if(carry>0){
            curr->next=new ListNode(carry);
        }
        return temp->next;
    }
};