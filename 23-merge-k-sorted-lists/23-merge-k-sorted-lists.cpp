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
    ListNode* merge(ListNode* a, ListNode* b)
    {
        ListNode* res = NULL;
        if(a == NULL) return (b);
        else if(b == NULL) return (a);
        if(a->val <= b->val){
            res = a;
            res->next = merge(a->next, b);
        }
        else{
            res = b;
            res->next = merge(a, b->next);
        }
        return res;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size(); // extracting size of array
        if(k == 0) // if size of array is value
            return NULL;
        
        int start = 0; // start pointer
        int last = k -1; // last pointer
        int temp;
        while(last != 0) // if last pointer not becomes zero
        {
            start = 0;
            temp = last;
            while(start < temp)
            {
                // merge them and store in one of the linked list
                lists[start] = merge(lists[start],lists[temp]);
                start++; // increment start
                temp--; // decrese start
                
                if(start >= temp) // if at any point start passes the temp
                {
                    last = temp;
                }
            }
        }
        return lists[0]; // return first linked list of the aray as now it contains the all nodes in the sorted order.
        
    }
};