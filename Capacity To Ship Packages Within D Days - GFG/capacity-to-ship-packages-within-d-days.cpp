//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int leastWeightCapacity(int arr[], int N, int D) {
        // code here
        int maxWeight=-1,totalWeight=0;
        for(int i=0;i<N;i++){
            maxWeight=max(maxWeight,arr[i]);
            totalWeight+=arr[i];
        }
        
        int low=maxWeight, high=totalWeight;
        while(low<high){
            int mid=low+(high-low)/2;
            
            int daysNeeded=1, currWeight=0;
            for(int i=0;i<N;i++){
                if(currWeight+arr[i]>mid){
                    daysNeeded++;
                    currWeight=0;
                }
                currWeight+=arr[i];
            }
            if(daysNeeded>D)
            low=mid+1;
            else
            high=mid;
        }
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends