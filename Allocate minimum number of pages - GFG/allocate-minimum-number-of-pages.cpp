//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    int countStudents(int a[], int mid, int n){
        int students=1;
        long long pageStudent=0;
        for(int i=0;i<n;i++){
            if(pageStudent+a[i]<=mid)
            pageStudent+=a[i];
            else
            {
                students++;
                pageStudent=a[i];
            }
        }
        return students;
    }
    
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(M>N) return -1;
        
        int low=*max_element(A,A+N);
        int high=accumulate(A,A+N,0);
        
        while(low<=high){
            int mid=(low+high)/2;
            int students=countStudents(A,mid,N);
            if(students>M)
            low=mid+1;
            else
            high=mid-1;
        }
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends