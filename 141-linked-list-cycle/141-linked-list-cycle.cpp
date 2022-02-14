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
    bool hasCycle(ListNode *head) {
       
        ListNode *fast = head;
        ListNode *slow = slow;
        
        while(fast != NULL && (fast->next) != NULL)
        {
            fast = fast->next-> next; // move fast 2 step
            slow = slow->next;         // move slow 1 step
            if(fast == slow)             // if fast & slow meets, means there is a cycle.
                return true;
        }
        return false;
    }
};