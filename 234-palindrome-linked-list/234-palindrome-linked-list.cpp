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
        ListNode* slow= head;    // Temp pointer
        stack <int> s;       // Declare a stack
        // Push all elements of the list to the stack
        while(slow != NULL){
                s.push(slow->val);
                slow = slow->next;        // Move ahead
        }
        // Iterate in the list again and check by popping from the stack
        while(head != NULL ){
             int i=s.top();          // Get the top most element
             s.pop();                // Pop the element
             // Check if data is not same as popped element
            if(head -> val != i){
                return false;
            }
           head=head->next;             // Move ahead
        }
return true;
    }
};