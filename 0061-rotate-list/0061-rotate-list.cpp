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
          if (head == NULL ||head->next == NULL || k == 0) return head;

    int len = 1;
    ListNode* curr = head;
    while (curr->next) {
        len++;
        curr = curr->next;
    }

    curr->next = head;
    int actualK = k % len;
    
    actualK=len-actualK;

    
    while(actualK--) {
        curr = curr->next;
    }

   head = curr->next;
    curr->next = NULL;

    // ListNode* temp = newHead;
    // while (temp->next) {
    //     temp = temp->next;
    // }
    // temp->next = head;

    return head;
    }
};