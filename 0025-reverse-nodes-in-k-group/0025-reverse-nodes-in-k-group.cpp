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
        ListNode* cursor=head;
        for(int i=0;i<k;i++){
            if(cursor==NULL) return head;
            cursor=cursor->next;
        }

        ListNode* curr=head, *prev=NULL, *nextNode=NULL;
        int count=0;
        for(int i=0;i<k;i++){
            nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }

        head->next=reverseKGroup(curr,k);
        return prev;
    }
};



/* Another approach
if(head==NULL || k==1) return head;

    Node* dummy=new Node();
    dummy->next=head;
    Node* pre=dummy, *curr=dummy, *nextNode=dummy;
   

    int len=0;
    while(curr){
        len++;
        curr=curr->next;
    }

    curr=head;

    while(len>=k){
        curr=pre->next;
        nextNode=curr->next;
        for(int i=1; i<k; i++){
            curr->next=nextNode->next;
            nextNode->next=pre->next;
            pre->next=nextNode;
            nextNode=curr->next;
        }
        pre=curr;
        len-=k;
    }
    return dummy->next;
    */