//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        if(head==NULL || head->next==NULL) return head;
        
        Node* evenHead=NULL, *oddHead=NULL, *evenTail=NULL, *oddTail=NULL;
        
        Node* curr=head;
        
        while(curr){
            if(curr->data%2==0){
                if(evenHead==NULL){
                    evenHead=evenTail=curr;
                }
                else{
                    evenTail->next=curr;
                    evenTail=evenTail->next;
                }
            }
            else {
                if(oddHead==NULL){
                    oddHead=oddTail=curr;
                }
                else{
                    oddTail->next=curr;
                    oddTail=oddTail->next;
                }
            }
            curr=curr->next;
        }
        
        if(evenHead!=NULL)
        evenTail->next=oddHead;
        
        if(oddTail!=NULL)
        oddTail->next=NULL;
        
        if(evenHead!=NULL)
        head=evenHead;
        else
        head=oddHead;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends