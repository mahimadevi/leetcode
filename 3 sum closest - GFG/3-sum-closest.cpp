//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int closest3Sum(int a[], int n, int target)
    {
        // code herea.
        
        sort(a,a+n);
        int diff=INT_MAX;
        int ans=0;
        for(int i=0;i<n;i++){
           int first=a[i];
           int start = i+1;
           int end=n-1;
           while (start<end){
               if(first+a[start]+a[end]==target)
               return target;
               else if(abs(first+a[start]+a[end]-target)<diff){
                   diff=abs(first+a[start]+a[end]-target);
                   ans=first+a[start]+a[end];
               }
               if(first+a[start]+a[end]-target>diff) end--;
               else start++;
           }
           
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}
// } Driver Code Ends