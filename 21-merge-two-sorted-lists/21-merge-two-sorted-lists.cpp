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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* first = list1;
        ListNode* second = list2;
        ListNode *ans = new ListNode(-1);
        ListNode* A = ans;
        while(first != NULL && second != NULL) {
            if((first->val) >= (second->val)) {
                ans -> next = second;
                second = second -> next;
                ans = ans -> next;
            }
            else {
                ans -> next = first;
                first = first -> next;
                ans = ans -> next;
            }
        }
        while(first != NULL) {
            ans -> next = first;
            first = first -> next;
            ans = ans -> next;
        }
        while(second != NULL) {
            ans -> next = second;
            second = second -> next;
            ans = ans -> next;
        }
        A = A -> next;
        return A;
         
    }
};