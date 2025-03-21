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
    ListNode* merge(ListNode* l1,ListNode* l2){
		if(l1==NULL && l2==NULL)return NULL;
		if(l1==NULL)return l2;
		if(l2==NULL)return l1;
		ListNode *temp,*tail;
		if(l1->val>l2->val){
			temp=l2;
			tail=l2;
			l2=l2->next;
		}
		else{
			temp=l1;
			tail=l1;
			l1=l1->next;
		}
		while(l1!=NULL || l2!=NULL){
			if(l1!=NULL && l2!=NULL){
				if(l1->val > l2->val){
					tail->next=l2;
					l2=l2->next;
					tail=tail->next;
				}
				else{
					tail->next=l1;
					l1=l1->next;
					tail=tail->next;
				}
			}
			else if(l1!=NULL){
				tail->next=l1;
				break;
			}
			else{
				tail->next=l2;
				break;
			}
		}
		return temp;
	}

	ListNode* sortList(ListNode* head) {
		if(head==NULL || head->next==NULL)return head;
		ListNode *slow=head,*fast=head,*prev=head;
		while(fast!=NULL && fast->next!=NULL){  //to find mid of list
			prev=slow;
			slow=slow->next;
			fast=fast->next->next;
		}
		prev->next=NULL;
		head=sortList(head);  //to divide list from start to mid into 1-1 elements
		slow=sortList(slow);  //to divide list from mid to end into 1-1 elements
		return merge(head,slow);   //merging again ad forms sorted list
	}
};