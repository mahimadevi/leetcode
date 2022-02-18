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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0;
    int len2 = 0;
    
    ListNode* temp = headA;
    ListNode* other;
	
	// Calculating the length of list 1
    while(temp!=NULL) { len1++; temp = temp->next;}
    temp = headB;
	
	// Calculating the length of list 2
    while(temp!=NULL) { len2++; temp = temp->next;}
    
	// Difference of lengths
    int Diff = abs(len1-len2);
    
	// Idea is if len1 > len 2 then start list 1 pointer ahead by diff and list 2 pointer from start and vice versa.
    if(len1>len2){
        temp  = headA;
        while(Diff--) temp = temp->next;
        other = headB;
    }else{
        temp  = headB;
        while(Diff--) temp = temp->next;
        other = headA;
    }
    
	// Now excluding the diff the length of both lists will be same 
	// and they have to meet somewhere when we increase pointer one by one or else if NULL , there is no intersection.
    while(temp!=NULL and other!=NULL){
        if(temp==other) return other;  // if at any point the become same
        temp = temp->next;
        other = other->next;
    }
    return NULL;
    }
};