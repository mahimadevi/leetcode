//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int l = min(arr1[0], arr2[0]), r = max(arr1[n-1], arr2[m-1]);
        while (l<=r)    {
            int mid = l+(r-l)/2;
            int small1 = lower_bound(arr1, arr1+n, mid)-arr1; // gives count of elements smaller than mid in arr1
            int small2 = lower_bound(arr2, arr2+m, mid)-arr2; // gives count of elements smaller than mid in arr2
            // if small1+small2 is k-1 i.e. we found k-1 values smaller than mid, then mid might possibly be the kth largest element
            // so we check if mid exists in either of arr1 or arr2
            if (small1+small2==k-1)   {
                // if value at lower_bound of either arr1 or arr2 is mid, then we found our kth largest
                if (*lower_bound(arr1, arr1+n, mid)==mid or 
                    *lower_bound(arr2, arr2+m, mid)==mid)   return mid;
                // else it should definitely exist on right side of mid
                else    l = mid+1;
            }   else if (small1+small2<k-1)   {
                l = mid+1;
            }   else    {
                r = mid-1;
            }
        }
        return r;
        
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends