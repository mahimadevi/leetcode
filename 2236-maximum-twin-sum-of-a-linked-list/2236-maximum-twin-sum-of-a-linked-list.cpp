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
    int pairSum(ListNode* head) {
        // Step 1: Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Push the values of the first half into a stack
        stack<int> st;
        ListNode* curr = head;
        while (curr != slow) {
            st.push(curr->val);
            curr = curr->next;
        }

        // Step 3: Traverse the second half and calculate twin sums
        int maxSum = 0;
        while (slow) {
            int twinSum = slow->val + st.top();
            st.pop();
            maxSum = max(maxSum, twinSum);
            slow = slow->next;
        }

        // Step 4: Return the maximum twin sum
        return maxSum;
    }
};

/**
 * Explanation of the Code:
 * 1. We use the slow and fast pointer technique to find the middle of the linked list.
 * 2. We push the values of the first half of the list into a stack.
 * 3. We traverse the second half of the list, popping values from the stack to calculate twin sums.
 * 4. We keep track of the maximum twin sum encountered.
 * 5. Finally, we return the maximum twin sum.
 */