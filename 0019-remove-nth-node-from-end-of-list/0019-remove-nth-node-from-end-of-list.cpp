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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node to handle edge cases
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    // Calculate the length of the list
    int length = 0;
    ListNode* curr = head;
    while (curr != nullptr) {
        length++;
        curr = curr->next;
    }

    // Calculate the position of the node to remove from the beginning
    int position = length - n;

    // Traverse to the node before the one to remove
    curr = dummy;
    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }

    // Remove the node
    ListNode* temp = curr->next;
    curr->next = curr->next->next;
    delete temp;

    return dummy->next;
    }
};