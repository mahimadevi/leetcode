//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    
	    int i=0,j=n-1;
    int start=-1,end=-1;
    
    vector<int>ans;
    
    while(i<=j){
        int mid=(i+j)/2;
        
        if(arr[mid]==x){
            int temp=mid;
            
            while(mid>0 && arr[mid-1]==x)
            mid--;
            start=mid;
            
            while(temp<n-1 && arr[temp+1]==x)
            temp++;
            end=temp;
            
           return end-start+1;
        }
        
        else if(arr[mid]>x)
        j=mid-1;
        
        else
        i=mid+1;
    }
    
    return 0;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends